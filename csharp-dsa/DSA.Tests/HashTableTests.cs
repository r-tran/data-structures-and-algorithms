using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Security.Principal;
using DSA.HashTable;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace DSA.Tests
{
    [TestClass]
    public class HashTableTests
    {
        [TestMethod]
        public void HashTable_Ctor_InitializesTable()
        {
            var table = new HashTable<string, int>();
            Assert.AreEqual(0, table.Size);
        }

        [TestMethod]
        public void HashTable_HashFunction_CompressesCorrectly()
        {
            var table = new HashTable<string, int>();
            string[] keys = {"hello", "myname", "is", "ray", "tran"};
            foreach (var testkey in keys)
            {
                var index = table.Hash(testkey);
                Assert.IsTrue(index >= 0 && index < table.Capacity);
            }
        }

        [TestMethod]
        public void HashTable_AddNewKey_TableUpdatesCorrectly()
        {
            var table = new HashTable<string, int>();
            table.Add("hello", 1);
            table.Add("world!", 2);
            table.Add("my name is", 3);
            Assert.AreEqual(11, table.Capacity);
            Assert.AreEqual(3, table.Size);
            Console.WriteLine(table.LoadFactor);
            table.PrintTable();
        }

        [TestMethod]
        public void HashTable_AddExistingKey_TableUpdatesCorrectly()
        {
            var table = new HashTable<string, int>();
            table.Add("hello", 1);
            table.Add("world!", 2);
            table.Add("my name is", 3);
            table.Add("hello", 100);
            Assert.AreEqual(11, table.Capacity);
            Assert.AreEqual(3, table.Size);
            Assert.AreEqual(100, table["hello"]);
        }

        [TestMethod]
        public void HashTable_AddLoadFactorExceeded_TableUpdatesCorrectly()
        {
            var table = new HashTable<string, int>
            {
                {"hello", 1},
                {"world!", 2},
                {"my name is", 3},
                {"barney", 4},
                {"the big", 5}
            };
            Assert.AreEqual(5, table.Size);
            Assert.AreEqual(11, table.Capacity);

            table.Add("white elephant", 6);
            Assert.AreEqual(22, table.Capacity);
            Assert.AreEqual(6, table.Size);
            foreach (var key in table)
            {
                Assert.IsTrue(table.Exists(key));
            }

            table.PrintTable();
        }

        [ExpectedException(typeof(KeyNotFoundException))]
        [TestMethod]
        public void HashTable_RemoveKey_KeyDoesNotExistThrowsError()
        {
            var table = new HashTable<string, int>
            {
                {"hello", 1},
                {"world!", 2},
                {"my name is", 3},
                {"barney", 4},
                {"the big", 5}
            };

            table.RemoveKey("heLlo");
        }


        [TestMethod]
        public void HashTable_RemoveKey_UpdatesTableExpectedly()
        {
            var table = new HashTable<string, int>
            {
                {"hello", 1},
                {"world!", 2},
                {"my name is", 3},
                {"barney", 4},
                {"the big", 5}
            };
            table.RemoveKey("hello");
            Assert.AreEqual(4, table.Size);
            table.RemoveKey("the big");
            Assert.AreEqual(3, table.Size);
            table.RemoveKey("world!");
            Assert.AreEqual(2, table.Size);
            table.RemoveKey("my name is");
            Assert.AreEqual(1, table.Size);
            table.RemoveKey("barney");
            Assert.AreEqual(0, table.Size);
        }

        [TestMethod]
        public void HashTable_RemoveSentinel_OtherKeysStillAccessible()
        {
            var table = new HashTable<string, int>
            {
                {"hello", 1},
                {"world!", 2},
                {"my name is", 3},
                {"barney", 4},
                {"the big", 5}
            };
            table.RemoveKey("hello");
            string[] keys = {"world!", "my name is", "barney", "the big"};
            foreach (var key in keys)
                Assert.IsTrue(table.Exists(key));
        }

        [TestMethod]
        public void HashTable_Exists_ReturnsAsExpected()
        {
            var table = new HashTable<string, int>
            {
                {"hello", 1},
                {"world!", 2},
                {"my name is", 3},
                {"barney", 4},
                {"the big", 5}
            };

            Assert.IsTrue(table.Exists("barney"));
            Assert.IsFalse(table.Exists("dinosaur"));
        }

        [TestMethod]
        public void HashTable_GetKeyValue_ReturnsAsExpected()
        {
            var table = new HashTable<string, int>
            {
                {"hello", 1},
                {"world!", 2},
                {"my name is", 3},
                {"barney", 4},
                {"the big", 5}
            };

            Assert.AreEqual(4, table["barney"]);
        }

        [ExpectedException(typeof(KeyNotFoundException))]
        [TestMethod]
        public void HashTable_GetKeyValueNotFound_ThrowsException()
        {
            var table = new HashTable<string, int>
            {
                {"hello", 1},
                {"world!", 2},
                {"my name is", 3},
                {"barney", 4},
                {"the big", 5}
            };

            var throwHere = table["hi"];
        }
    }
}

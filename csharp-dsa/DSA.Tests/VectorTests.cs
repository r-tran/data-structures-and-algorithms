using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using DSA.Vector;

namespace DSA.Tests
{
    [TestClass]
    public class VectorTests
    {
        [TestMethod]
        public void Vector_Ctor_DefaultCapacityIsSet()
        {
            Vector<int> v = new Vector<int>();

            Assert.AreEqual(16, v.Capacity);           
        }

        [TestMethod]
        public void Vector_Ctor_ExpectedCapacityScalesByGrowthFactor()
        {
            int[] powersOfTwo = {16, 32, 64, 128, 256};

            foreach (var num in powersOfTwo)
            {
                Vector<int> v = new Vector<int>(num);

                Assert.AreEqual(num, v.Capacity);
            }            
        }

        [TestMethod]
        public void Vector_Ctor_CapacityScalesByGrowthFactor()
        {
            int[] powersOfTwo = { 16, 32, 64, 128, 256 };

            int[] vectorCapacityInput = {1, 20, 40, 100, 200};
            for (int i = 0; i < powersOfTwo.Length; i++)
            {
                Vector<int> v = new Vector<int>(vectorCapacityInput[i]);

                Assert.AreEqual(powersOfTwo[i], v.Capacity);
            }
        }

        [TestMethod]
        public void Vector_Size_EmptyArray()
        {
            Vector<string> v = new Vector<string>();

            Assert.AreEqual(0, v.Size);
        }

        [TestMethod]
        public void Vector_PushBack_ChangesSize()
        {
            Vector<int> v = new Vector<int>();

            v.PushBack(1);
            v.PushBack(2);
            v.PushBack(3);
            v.PushBack(4);
            v.PushBack(5);

            Assert.AreEqual(5, v.Size);
        }

        [TestMethod]
        public void Vector_PushBack_InsertsElements()
        {
            Vector<int> v = new Vector<int>();
            int[] sol = new int[16];
            for (int i = 1; i <= 5; i++)
                sol[i - 1] = i;

            v.PushBack(1);
            v.PushBack(2);
            v.PushBack(3);
            v.PushBack(4);
            v.PushBack(5);
            
            CollectionAssert.AreEqual(sol, v.Data);
        }

        [TestMethod]
        public void Vector_PushBack_ResizesUp()
        {
            Vector<int> v = new Vector<int>();
            for (int i = 0; i < 16; i++)
                v.PushBack(i);
            Assert.AreEqual(16, v.Capacity);

            v.PushBack(17);

            Assert.AreEqual(32, v.Capacity);
        }

        [ExpectedException(typeof(IndexOutOfRangeException))]
        [TestMethod]
        public void Vector_InsertItem_AtBack()
        {
            Vector<int> v = new Vector<int>();
            v.PushBack(4);
            v.PushBack(2);
            v.Insert(3, 10);                    
        }

        [TestMethod]
        public void Vector_InsertItem_ItemInsertedInMiddle()
        {
            Vector<int> v = new Vector<int>();
            int[] sol = { 1, 2, 3, 4, 11, 5, 6, 7, 8, 9, 10, 0, 0, 0, 0, 0};
            for (int i = 1; i <= 10; i++)
                v.PushBack(i);

            v.Insert(4, 11);
            
            CollectionAssert.AreEqual(sol, v.Data);         
        }

        [TestMethod]
        public void Vector_InsertItem_ItemInsertedAtFront()
        {
            Vector<int> v = new Vector<int>();
            int[] sol = { 11, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 0, 0, 0, 0 };
            for (int i = 1; i <= 10; i++)
                v.PushBack(i);

            v.Insert(0, 11);

            CollectionAssert.AreEqual(sol, v.Data);
        }

        [TestMethod]
        public void Vector_InsertItem_SizeUp()
        {
            Vector<int> v = new Vector<int>();
            int[] sol = new int[256];
            sol[64] = 100;
            for (int i = 0; i < 128; i++)
                v.PushBack(0);
            Assert.AreEqual(v.Capacity, 128);

            v.Insert(64, 100);

            CollectionAssert.AreEqual(sol, v.Data);
            Assert.AreEqual(256, v.Capacity);
        }

        [TestMethod]
        public void Vector_AtIndex_ReturnsCorrectValue()
        {
            Vector<int> v = new Vector<int>();
            for (int i = 1; i <= 256; i++)            
                v.PushBack(i);

            int val = v.At(199);

            Assert.AreEqual(200, val);
        }

        [ExpectedException(typeof(IndexOutOfRangeException))]
        [TestMethod]
        public void Vector_AtIndex_ThrowsIndexOutOfRangeException()
        {
            Vector<string> v = new Vector<string>();
            for (int i = 0; i < 100; i++)
                v.PushBack(i.ToString());

            v.At(129);
        }

        [TestMethod]
        public void Vector_Prepend_InsertsAtFront()
        {
            Vector<int> v = new Vector<int>();
            int[] sol = {100, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0};
            for (int i = 0; i < 10; i++)
                v.PushBack(i);

            v.Prepend(100);

            CollectionAssert.AreEqual(sol, v.Data);            
        }

        [TestMethod]
        public void Vector_Pop_RemovesAndReturnsElements()
        {
            Vector<int> v = new Vector<int>();
            for (int i = 1; i <= 16; i++)            
                v.PushBack(i);

            for (int i = 16; i > 0; i--)
            {
                var val = v.Pop();

                Assert.AreEqual(i - 1, v.Size);
                Assert.AreEqual(i, val);
            }       
        }        

        [TestMethod]
        public void Vector_Pop_ResizeDown()
        {
            Vector<int> v = new Vector<int>();
            for (int i = 1; i <= 64; i++)
                v.PushBack(i);
            Assert.AreEqual(64, v.Capacity);

            for (int i = 0; i < 48; i++)
                v.Pop();

            Assert.AreEqual(32, v.Capacity);

            for (int i = 0; i < 12; i++)
                v.Pop();

            Assert.AreEqual(16, v.Capacity);
        }

        [ExpectedException(typeof(IndexOutOfRangeException))]
        [TestMethod]
        public void Vector_Delete_ThrowsIndexOutOfRange()
        {
            Vector<int> v = new Vector<int>();
            for (int i = 0; i < 10; i++)
                v.PushBack(i);

            v.Delete(10);
        }

        [TestMethod]
        public void Vector_DeleteAtFront_SuccessfulRemoval()
        {
            Vector<int> v = new Vector<int>();
            for (int i = 1; i <= 10; i++)
                v.PushBack(i);
            int[] sol = {2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 0, 0, 0, 0, 0, 0};

            v.Delete(0);

            CollectionAssert.AreEqual(sol, v.Data);
        }

        [TestMethod]
        public void Vector_DeleteAtMiddle_SuccessfulRemoval()
        {
            Vector<int> v = new Vector<int>();
            for (int i = 1; i <= 10; i++)
                v.PushBack(i);
            int[] sol = { 1, 2, 3, 4, 5, 7, 8, 9, 10, 0, 0, 0, 0, 0, 0, 0,};

            v.Delete(5);

            CollectionAssert.AreEqual(sol, v.Data);
        }

        [TestMethod]
        public void Vector_DeleteAtEnd_SuccessfulRemoval()
        {
            Vector<int> v = new Vector<int>();
            for (int i = 1; i <= 10; i++)
                v.PushBack(i);
            int[] sol = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0};

            v.Delete(9);

            CollectionAssert.AreEqual(sol, v.Data);
        }

        public void Vector_Delete_ResizeDown()
        {
            Vector<int> v =new Vector<int>();
            for (int i = 0; i < 256; i++)
                v.PushBack(i);
            Assert.AreEqual(256, v.Capacity);

            for (int i = 0; i <192; i++)
                v.Delete(0);            
            Assert.AreEqual(128, v.Capacity);

            for (int i = 0; i < 96; i++)
                v.Delete(0);
            Assert.AreEqual(64, v.Capacity);

            for (int i = 0; i < 48; i++)
                v.Delete(0);
            Assert.AreEqual(32, v.Capacity);

            for (int i = 0; i < 12; i++)
                v.Delete(0);
            Assert.AreEqual(16, v.Capacity);

            for (int i = 0; i < 3; i++)
                v.Delete(0);
            Assert.AreEqual(16, v.Capacity);
        }


        [TestMethod]
        public void Vector_Find_ReturnsCorrectIndex()
        {
            Vector<int> v = new Vector<int>();
            for (int i = 1; i <= 16; i++)
                v.PushBack(i);

            var index = v.Find(15);

            Assert.AreEqual(14, index);
        }

        [TestMethod]
        public void Vector_Find_IndexNotFound()
        {
            Vector<int> v = new Vector<int>();
            for (int i = 1; i <= 10; i++)
                v.PushBack(i);

            int val = v.Find(0);

            Assert.AreEqual(-1, val);
        }

        [TestMethod]
        public void Vector_Remove_SingleItem()
        {
            Vector<int> v = new Vector<int>();
            for (int i = 1; i <= 10; i++)
                v.PushBack(i);
            int[] sol = {1, 2, 3, 4, 5, 7, 8, 9, 10, 0, 0, 0, 0, 0, 0, 0};
            
            v.Remove(6);
            
            CollectionAssert.AreEqual(sol, v.Data);
        }

        [TestMethod]
        public void Vector_Remove_MultipleItems()
        {
            Vector<int> v = new Vector<int>();
            v.PushBack(1);
            v.PushBack(2);
            v.PushBack(3);
            v.PushBack(2);
            v.PushBack(5);
            v.PushBack(2);
            int[] sol = {1, 3, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

            v.Remove(2);

            CollectionAssert.AreEqual(sol, v.Data);
        }


        [TestMethod]
        public void Vector_Remove_AllItems()
        {
            Vector<int> v = new Vector<int>();
            for (int i = 0; i < 10; i++)
                v.PushBack(10);
            int[] sol = new int[16];

            v.Remove(10);

            Assert.AreEqual(0, v.Size);
            CollectionAssert.AreEqual(sol, v.Data);            
        }

        [TestMethod]
        public void Vector_Remove_ResizeDown()
        {
            Vector<int> v = new Vector<int>();
            for (int i =0; i < 64; i++)
                v.PushBack(i);

            for (int i = 0; i < 48; i++)
                v.Remove(i);
            Assert.AreEqual(32, v.Capacity);

            for (int i = 48; i < 56; i++)
                v.Remove(i);
            Assert.AreEqual(16, v.Capacity);

            for (int i = 57; i < 60; i++)
                v.Remove(i);
            Assert.AreEqual(16, v.Capacity);
        }

        [ExpectedException(typeof(IndexOutOfRangeException))]
        [TestMethod]
        public void Vector_Indexer_IndexOutOfRangeException()
        {
            Vector<int> v = new Vector<int>();
            v.PushBack(0);

            int val = v[1];
        }

        [TestMethod]
        public void Vector_Indexer_GetReturnCorrectValue()
        {
            Vector<int> v = new Vector<int>();
            for (int i = 1; i <= 3; i++)
                v.PushBack(i);

            var val = v[1];

            Assert.AreEqual(2, val);
        }

        [TestMethod]
        public void Vector_Indexer_SetInsertsCorrectValue()
        {
            Vector<int> v = new Vector<int>();
            int[] sol = { 1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

            for (int i = 1; i <= 3; i++)
                v[i - 1] = i;
            
            CollectionAssert.AreEqual(sol, v.Data);
        }

        [TestMethod]
        public void Vector_IEnumerable_ReturnsData()
        {
            Vector<int> v = new Vector<int>();
            int[] sol = new int[100];

            for (int i = 1; i <= 100; i++)
            {
                v.PushBack(i);
                sol[i - 1] = i;
            }

            foreach (var i in v)
            {
                Assert.AreEqual(sol[i-1], i);
            }
        }       
    }
}

using System;
using DSA.LinkedList;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace DSA.Tests
{
    [TestClass]
    public class SingleLinkListTests
    {
        [TestMethod]
        public void LinkList_Ctor_Default()
        {
            LinkList<string> list = new LinkList<string>();
            Assert.AreEqual(0, list.Size);
            Assert.IsTrue(list.IsEmpty);            
        }

        [ExpectedException(typeof(InvalidOperationException))]
        [TestMethod]
        public void LinkList_Back_EmptyList()
        {
            LinkList<string> list = new LinkList<string>();
            var data = list.Back;
        }

        [ExpectedException(typeof(InvalidOperationException))]
        [TestMethod]
        public void LinkList_Front_EmptyList()
        {
            LinkList<string> list = new LinkList<string>();
            var data = list.Front;
        }

        [TestMethod]
        public void LinkList_Insert_Front()
        {
            LinkList<int> list = new LinkList<int>();

            for (int i = 0; i < 10; i++)
                list.Insert(0, i + 1);

            Assert.AreEqual(10, list.Size);
            for (int i = 0; i < 10; i++)
                Assert.AreEqual(10 - i, list.ValueAt(i));
        }

        [TestMethod]
        public void LinkList_Insert_Back()
        {
            LinkList<int> list = new LinkList<int>();

            for (int i = 0; i < 10; i++)
                list.Insert(list.Size, i + 1);

            Assert.AreEqual(10, list.Size);
            for (int i = 0; i < 10; i++)
                Assert.AreEqual(i + 1, list.ValueAt(i));
        }

        [TestMethod]
        public void LinkList_Insert_Middle()
        {
            LinkList<int> list = new LinkList<int>();
            int[] sol = {1, 2, 100, 3, 4, 5};
            for (int i = 0; i < 5; i++)
                list.Insert(i, i + 1);            
            
            list.Insert(2, 100);

            for (int i = 0; i < 6; i++)
                Assert.AreEqual(sol[i], list.ValueAt(i));            
        }

        [TestMethod]
        public void LinkList_Erase_Front()
        {
            LinkList<int> list = new LinkList<int>();
            for (int i = 0; i < 10; i++)
                list.PushBack(i + 1);

            for (int i = 0; i < 9; i++)
            {
                list.Erase(0);
                Assert.AreEqual(list.ValueAt(0), i + 2);
                Assert.AreEqual(10 - i - 1, list.Size);
            }
            
            list.Erase(0);
            Assert.IsTrue(list.IsEmpty);
        }

        [TestMethod]
        public void LinkList_Erase_Middle()
        {
            LinkList<int> list = new LinkList<int>();
            int[] sol = {2, 3, 4, 5, 7, 8, 9};
            for (int i = 0; i < 10; i++)
                list.PushBack(i + 1);

            list.Erase(0);
            list.Erase(4);
            list.Erase(7);
            Assert.AreEqual(7, list.Size);
            for (int i = 0; i < 7; i++)
            {
                Assert.AreEqual(sol[i], list.ValueAt(i));
            }            
        }

        [TestMethod]
        public void LinkList_Erase_End()
        {
            LinkList<int> list = new LinkList<int>();
            for (int i = 0; i < 10; i++)
                list.PushBack(i + 1);

            for (int i = 9; i > 0; i--)
            {
                list.Erase(list.Size - 1);
                Assert.AreEqual(i, list.ValueAt(list.Size - 1));
            }

            Assert.AreEqual(1, list.Size);
            list.Erase(list.Size - 1);
            Assert.IsTrue(list.IsEmpty);
        }

        [TestMethod]
        public void LinkList_RemoveValue_Front()
        {
            LinkList<int> list = new LinkList<int>();
            int[] sol = { 2, 3, 4, 5, 6, 7, 8, 9, 10 };

            for (int i = 0; i < 10; i++)
                list.PushBack(i + 1);
            list.RemoveValue(1);

            Assert.AreEqual(9, list.Size);
            for (int i = 0; i < 9; i++)
            {
                Assert.AreEqual(sol[i], list.ValueAt(i));
            }
        }

        [TestMethod]
        public void LinkList_RemoveValue_Middle()
        {
            LinkList<int> list = new LinkList<int>();
            int[] sol = { 1, 2, 3, 5, 6, 7, 8, 9, 10 };

            for (int i = 0; i < 10; i++)
                list.PushBack(i + 1);
            list.RemoveValue(4);

            Assert.AreEqual(9, list.Size);
            for (int i = 0; i < 9; i++)
            {
                Assert.AreEqual(sol[i], list.ValueAt(i));
            }
        }

        [TestMethod]
        public void LinkList_RemoveValue_End()
        {
            LinkList<int> list = new LinkList<int>();
            int[] sol = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

            for (int i = 0; i < 10; i++)
                list.PushBack(i + 1);
            list.RemoveValue(10);

            Assert.AreEqual(9, list.Size);
            for (int i = 0; i < 9; i++)
            {
                Assert.AreEqual(sol[i], list.ValueAt(i));
            }            
        }

        [TestMethod]
        public void LinkList_RemoveValue_NotFound()
        {
            LinkList<int> list = new LinkList<int>();
            int[] sol = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};            
                        
            for (int i = 0; i < 10; i++)
                list.PushBack(i + 1);
            list.RemoveValue(20);

            for (int i = 0; i < 10; i++)
                Assert.AreEqual(sol[i], list.ValueAt(i));
            Assert.AreEqual(10, list.Size);
        }

        [TestMethod]
        public void LinkList_Enumerable()
        {
            LinkList<int> list = new LinkList<int>();
            int[] sol = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

            for (int i = 0; i < 10; i++)
                list.PushBack(i + 1);

            int index = 0;             
            foreach (var node in list)
            {
                Assert.AreEqual(sol[index], node);
                index++;
            }
            
        }

        [TestMethod]
        public void LinkList_Reverse()
        {
            LinkList<int> list = new LinkList<int>();
            for (int i = 0; i < 10; i++)
                list.PushBack(i + 1);

            list.Reverse();

            for (int i = 0; i < 10; i++)
            {
                Assert.AreEqual(10 - i, list.ValueAt(i));
            }

            Assert.AreEqual(10, list.Front);
        }
    }
}

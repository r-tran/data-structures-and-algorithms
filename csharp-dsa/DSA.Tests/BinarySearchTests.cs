using DSA.Binary_Search;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace DSA.Tests
{
    [TestClass]
    public class BinarySearchTests
    {
        [TestMethod]
        public void BinarySearch_Iterative_FindsKey()
        {
            int[] array = {1, 2, 3, 4, 5, 6, 7};
            var index = BinarySearch<int>.IterativeBinarySearch(array, 6);
            Assert.AreEqual(5, index);
        }

        [TestMethod]
        public void BinarySearch_IterativeSingleElement_FindsKey()
        {
            int[] array = {100};
            var index = BinarySearch<int>.IterativeBinarySearch(array, 100);
            Assert.AreEqual(0, index);
        }

        [TestMethod]
        public void BinarySearch_RecursiveSingleElement_FindsKey()
        {
            int[] array = {100};
            var index = BinarySearch<int>.RecursiveBinarySearch(array, 0, 0, 100);
            Assert.AreEqual(0, index);
        }


        [TestMethod]
        public void BinarySearch_Iterative_KeyNotFound()
        {
            int[] array = { 1, 2, 3, 4, 5, 6};
            var index = BinarySearch<int>.IterativeBinarySearch(array, 8);
            Assert.AreEqual(-1, index);
        }

        [TestMethod]
        public void BinarySearch_Recursive_FindsKey()
        {
            int[] array = { 1, 2, 3, 4, 5, 6, 7 };
            var index = BinarySearch<int>.RecursiveBinarySearch(array, 0, 6, 6);
            Assert.AreEqual(5, index);
        }

        [TestMethod]
        public void BinarySearch_Recursive_KeyNotFound()
        {
            int[] array = { 1, 2, 3, 4, 5, 6 };
            var index = BinarySearch<int>.RecursiveBinarySearch(array, 0, 5, 8);
            Assert.AreEqual(-1, index);
        }
    }
}

using DSA.Queue;
using Microsoft.VisualStudio.TestTools.UnitTesting;


namespace DSA.Tests
{
    [TestClass]
    public class ArrayQueueTests
    {
        [TestMethod]
        public void BreakMe()
        {
            var queue = new ArrayQueue<int>();
            queue.Enqueue(1);
            queue.Dequeue();

            queue.Enqueue(1);
            queue.Dequeue();

            queue.Enqueue(1);
            queue.Dequeue();

            queue.Enqueue(1);
            queue.Dequeue();

            queue.Enqueue(1);
            queue.Dequeue();

            queue.Enqueue(1);
        }

        [TestMethod]
        public void ArrayQueue_Ctor_InitalizeEmptySize()
        {
            var queue = new ArrayQueue<int>();
            Assert.AreEqual(0, queue.Size);
        }

        [TestMethod]
        public void ArrayQueue_Size_UpdatesExpectedly()
        {
            var queue = new ArrayQueue<int>();
            for (int i = 0; i < 100; i++)
            {
                queue.Enqueue(i + 1);
                Assert.AreEqual(i + 1, queue.Size);
            }
            for (int i = 0; i < 100; i++)
            {
                queue.Dequeue();
                Assert.AreEqual(100 - i - 1, queue.Size);
            }
        }

        [TestMethod]
        public void ArrayQueue_IsEmpty_UpdatesExpectedly()
        {
            var queue = new ArrayQueue<int>();
            Assert.IsTrue(queue.IsEmpty);

            for (int i = 0; i < 100; i++)
                queue.Enqueue(i + 1);

            Assert.IsFalse(queue.IsEmpty);

            for (int i = 0; i < 100; i++)
            {
                queue.Dequeue();
            }

            Assert.IsTrue(queue.IsEmpty);
        }

        [ExpectedException(typeof(QueueEmptyException))]
        [TestMethod]
        public void ArrayQueue_FrontEmptyQueue_ThrowsEmptyException()
        {
            var queue = new ArrayQueue<int>();
            var val = queue.Front;
        }

        [TestMethod]
        public void ArrayQueue_Front_UpdatesExpectedly()
        {
            var queue = new ArrayQueue<int>();

            for (int i = 0; i < 100; i++)
            {
                queue.Enqueue(i + 1);
                Assert.AreEqual(1, queue.Front);
            }

            for (int i = 0; i < 100; i++)
            {
                Assert.AreEqual(i + 1, queue.Front);
                queue.Dequeue();
            }
        }

        [TestMethod]
        public void ArrayQueue_Enqueue_AddsElementAtFront()
        {
            var queue = new ArrayQueue<string>();
            queue.Enqueue("cat");
            queue.Enqueue("dog");
            queue.Enqueue("catdog");
            Assert.AreEqual(3, queue.Size);
            Assert.AreEqual("cat", queue.Front);
        }

        [ExpectedException(typeof(QueueEmptyException))]
        [TestMethod]
        public void ArrayQueue_DequeueEmptyQueue_ThrowsEmptyException()
        {
            var queue = new ArrayQueue<string>();
            var val = queue.Dequeue();
        }

        [TestMethod]
        public void ArrayQueue_Dequeue_ReturnsCorrectValue()
        {
            var queue = new ArrayQueue<string>();
            queue.Enqueue("cat");
            queue.Enqueue("dog");
            queue.Enqueue("catdog");

            var e1 = queue.Dequeue();
            Assert.AreEqual("cat", e1);

            var e2 = queue.Dequeue();
            Assert.AreEqual("dog", e2);

            var e3 = queue.Dequeue();
            Assert.AreEqual("catdog", e3);
        }

        [TestMethod]
        public void ArrayQueue_EnqueueDequeue_TestCircularStructure()
        {
            var queue = new ArrayQueue<int>();
            for (int i = 0; i < 100; i++)
            {
                queue.Enqueue(i + 1);
            }
            for (int i = 0; i < 50; i++)
            {
                queue.Dequeue();
            }
            for (int i = 0; i < 50; i++)
            {
                queue.Enqueue(i + 101);
            }

            Assert.AreEqual(51, queue.Front);
            Assert.AreEqual(100, queue.Size);
        }
    }
}

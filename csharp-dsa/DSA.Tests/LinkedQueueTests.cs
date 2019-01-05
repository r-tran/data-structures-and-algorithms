using DSA.Queue;
using Microsoft.VisualStudio.TestTools.UnitTesting;


namespace DSA.Tests
{
    [TestClass]
    public class LinkedQueueTests
    {
        [TestMethod]
        public void LinkedQueue_Ctor_InitalizeEmptySize()
        {
            var queue = new LinkedQueue<int>();
            Assert.AreEqual(0, queue.Size);
        }

        [TestMethod]
        public void LinkedQueue_Size_UpdatesExpectedly()
        {
            var queue = new LinkedQueue<int>();
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
        public void LinkedQueue_IsEmpty_UpdatesExpectedly()
        {
            var queue = new LinkedQueue<int>();
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
        public void LinkedQueue_FrontEmptyQueue_ThrowsEmptyException()
        {
            var queue = new LinkedQueue<int>();
            var val = queue.Front;
        }

        [TestMethod]
        public void LinkedQueue_Front_UpdatesExpectedly()
        {
            var queue = new LinkedQueue<int>();

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
        public void LinkedQueue_Enqueue_AddsElementAtFront()
        {
            var queue = new LinkedQueue<string>();
            queue.Enqueue("cat");
            queue.Enqueue("dog");
            queue.Enqueue("catdog");
            Assert.AreEqual(3, queue.Size);
            Assert.AreEqual("cat", queue.Front);
        }

        [ExpectedException(typeof(QueueEmptyException))]
        [TestMethod]
        public void LinkedQueue_DequeueEmptyQueue_ThrowsEmptyException()
        {
            var queue = new LinkedQueue<string>();
            var val = queue.Dequeue();
        }

        [TestMethod]
        public void LinkedQueue_Dequeue_ReturnsCorrectValue()
        {
            var queue = new LinkedQueue<string>();
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
    }
}

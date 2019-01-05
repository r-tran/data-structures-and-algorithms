using System;
using System.Collections;
using System.Collections.Generic;

namespace DSA.Queue
{
    public class LinkedQueue<T> : IQueue<T>
    {
        #region Constructor               

        public LinkedQueue()
        {
            Head = null;
            Tail = null;
            Size = 0;
        }

        #endregion

        #region Properties

        private Node<T> Head { get; set; }

        private Node<T> Tail { get; set; }

        public int Size { get; private set; }

        public bool IsEmpty => (Size == 0 && Head == null && Tail == null);

        public T Front
        {
            get
            {
                if (IsEmpty)
                    throw new QueueEmptyException("The queue is empty");
                return Head.Element;
            }
        }

        #endregion

        #region Methods

        public void Enqueue(T element)
        {
            var node = new Node<T>(null, element);
            if (IsEmpty)
                Head = node;                           
            else            
                Tail.Next = node;

            Tail = node;
            Size++;
        }

        public T Dequeue()
        {
            if (IsEmpty)
                throw new QueueEmptyException("The queue is empty");

            var val = Head.Element;
            if (Size == 1)                            
                Tail = null;
            Head = Head.Next;
            Size--;

            return val;
        }

        #endregion
    }    

    internal class Node<T>
    {
        internal Node<T> Next { get; set; }

        internal T Element { get; }

        internal Node(Node<T> next, T element)
        {
            Next = next;
            Element = element;
        }
    }
}

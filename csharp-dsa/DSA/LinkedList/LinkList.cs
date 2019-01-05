using System;
using System.Collections;
using System.Collections.Generic;

namespace DSA.LinkedList
{
    public class LinkList<T> : ILinkList<T>
    {
        #region Fields

        private Node<T> _head;

        #endregion

        #region Constructors

        public LinkList()
        {
            _head = null;
            Size = 0;
        }               

        #endregion

        #region Properties              

        public T Back
        {
            get
            {
                if (_head == null) throw new InvalidOperationException("List is empty");
                return ValueAt(Size - 1);
            }
        }

        public T Front
        {
            get
            {
                if (_head == null) throw new InvalidOperationException("Head is empty");
                return _head.Data;
            }
        }

        public bool IsEmpty => Size == 0;

        public int Size { get; private set; }

        #endregion

        #region Methods
              
        public void Erase(int index)
        {
            if (index < 0 || index > Size - 1)
                throw new IndexOutOfRangeException();
            if (_head == null || Size == 0)
                throw new InvalidOperationException();
            
            if (index == 0)
            {                
                _head = _head.Next;
                Size--;
                return;
            }

            var prev = _head;
            var curr = _head.Next;
            int i = 1;
            while (curr != null && i < index)
            {
                curr = curr.Next;
                prev = prev.Next;
                i++;
            }

            prev.Next = curr?.Next ?? null;
            Size--;
        }

        public IEnumerator<T> GetEnumerator()
        {
            var curr = _head;
            while (curr != null)
            {
                yield return curr.Data;
                curr = curr.Next;
            }
        }

        public void Insert(int index, T value)
        {
            if (index < 0 || index > Size)
                throw new IndexOutOfRangeException();            

            var curr = _head;
            int i = 1;
            var node = new Node<T>(value);

            if (index == 0)
            {
                if (_head != null)
                    node.Next = _head;
                _head = node;
                Size++;
                return;
            }

            while (i < index && curr.Next != null)
            {                
                i++;
                curr = curr.Next;
            }

            if (curr.Next != null)
                node.Next = curr.Next;
            curr.Next = node;
            Size++;
        }

        public T PopBack()
        {
            var val = ValueAt(Size - 1);
            Erase(Size - 1);
            return val;
        }

        public T PopFront()
        {
            var val = ValueAt(0);
            Erase(0);
            return val;
        }

        public void PushBack(T value)
        {
            Insert(Size, value);
        }

        public void PushFront(T value)
        {
            Insert(0, value);
        }

        public void RemoveValue(T value)
        {
            if (Size <= 0 || _head == null)
                throw new InvalidOperationException();            

            if (_head.Data.Equals(value))
            {
                _head = _head.Next;
                Size--;
                return;
            }

            var prev = _head;
            var curr = _head.Next;
            while (curr != null)
            {
                if (curr.Data.Equals(value))
                {
                    if (_head == curr)
                    {
                        _head = curr.Next;
                        Size--;
                        return;
                    }

                    prev.Next = curr.Next;
                    Size--;
                    return;
                }

                curr = curr.Next;
                prev = prev.Next;
            }
        }

        public void Reverse()
        {
            if (Size <= 1) return;

            var prev = _head;
            var curr = _head.Next;
            var next = curr;

            while (next.Next != null)
            {
                next = next.Next;
                curr.Next = prev;
                prev = curr;
                curr = next;
            }

            curr.Next = prev;
            _head = curr;
        }

        public T ValueAt(int index)
        {
            if (index < 0 || index > Size - 1)
                throw new IndexOutOfRangeException();

            if (_head == null)
                throw new InvalidOperationException();

            int i = 0;                      
            var curr = _head;

            while (i < index)
            {
                curr = curr.Next;
                i++;
            }

            return curr.Data;
        }

        public T ValueNFromEnd(int n)
        {
            return ValueAt(Size - n - 1);
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        #endregion
    }
}

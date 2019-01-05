using System;
using System.Collections;
using System.Collections.Generic;

namespace DSA.Vector
{
    public class Vector<T> : IVector<T>
    {
        private const int MinimumCapacity = 16;
        private const int GrowthFactor = 2;
        private const int ShrinkCapacity = 4;
        private const int ShrinkFactor = 2;

        private T[] _data;

        #region Constructor
        public Vector(int capacity = 16)
        {
            var trueCapacity = MinimumCapacity;
            while (trueCapacity < capacity)
                trueCapacity *= GrowthFactor;

            _data = new T[trueCapacity];
            Capacity = trueCapacity;
            Size = 0;
        }
        #endregion        

        #region Properties

        public T this[int i]
        {
            get
            {
                if (i < 0  || i >= Size)
                    throw new IndexOutOfRangeException();
                return _data[i];
            }

            set { Insert(i, value);}
        } 

        public T[] Data => _data;

        public int Size { get; private set; }

        public int Capacity { get; private set; }

        public bool IsEmpty => Size == 0;

        #endregion        

        #region Methods
        public T At(int index)
        {
            if (index < 0 || index > Capacity)
                throw new IndexOutOfRangeException();
            return _data[index];
        }

        public void PushBack(T item)
        {
            if (Size == Capacity)
                ResizeUp();
            _data[Size] = item;
            Size++;
        }        

        public void Insert(int index, T item)
        {
            if (index > Size || index < 0)
                throw new IndexOutOfRangeException();

            if (Size == Capacity)
                ResizeUp();

            for (int i = Size; i > index; i--)            
                _data[i] = _data[i - 1];

            _data[index] = item;
            Size++;
        }

        public void Prepend(T item)
        {
            Insert(0, item);
        }

        public T Pop()
        {
            var item = _data[Size - 1];
            _data[Size - 1] = default(T);
            Size--;

            if (Size * ShrinkCapacity == Capacity && Capacity > MinimumCapacity)
                ResizeDown();

            return item;
        }

        public void Delete(int index)
        {
            if (index < 0 || index >= Size)
                throw new IndexOutOfRangeException();

            for (int i = index; i < Size - 1; i++)            
                _data[i] = _data[i + 1];
            
            _data[Size - 1] = default(T);

            Size--;
            if (Size * ShrinkCapacity == Capacity && Capacity > MinimumCapacity)
                ResizeDown();
        }

        public void Remove(T item)
        {
            for (int i = 0; i < Size; i++)
            {
                if (EqualityComparer<T>.Default.Equals(item, _data[i]))                                
                    Delete(i--);                                    
            }                     
        }

        public int Find(T item)
        {
            for (int i = 0; i < Size; i++)
            {
                if (EqualityComparer<T>.Default.Equals(item, _data[i]))                
                    return i;                
            }

            return -1;
        }

        private void ResizeUp()
        {
            Capacity *= 2;
            T[] newarr = new T[Capacity];

            for (int i = 0; i < Size; i++)
                newarr[i] = _data[i];

            _data = newarr;
        }

        private void ResizeDown()
        {
            Capacity /= ShrinkFactor;
            T[] newarr = new T[Capacity];

            for (int i = 0; i < Size; i++)
                newarr[i] = _data[i];

            _data = newarr;
        }

        public IEnumerator<T> GetEnumerator()
        {
            for (int i = 0; i < Size; i++)
                yield return _data[i];
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
        #endregion       
    }
}

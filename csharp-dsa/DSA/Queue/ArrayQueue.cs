using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace DSA.Queue
{
    public class ArrayQueue<T> : IQueue<T>
    {
        #region Fields                
        private const int ScaleFactor = 2;
        private const int DefaultCapacity = 16;
        private const int Shrink = 4; 
        private int _first;
        #endregion

        #region Properties

        private T[] Data { get; set; }

        public bool IsEmpty => Size == 0;

        public int Size { get; private set; }

        public T Front
        {
            get
            {
                if (IsEmpty)
                    throw new QueueEmptyException("The queue is empty!");
                return Data[_first];
            }            
        }

        #endregion

        #region Constructor

        public ArrayQueue()
        {
            Data = new T[DefaultCapacity];
            Size = 0; 
        }        

        #endregion
        #region Methods               
        public void Enqueue(T element)
        {
            if (Size == Data.Length)
                Resize(Data.Length * ScaleFactor);
            var idx = (_first + Size) % Data.Length;
            Data[idx] = element;
            Size++;
        }

        public T Dequeue()
        {
            if (IsEmpty)
                throw new QueueEmptyException("The queue is empty!");

            var value = Front;
            Data[_first] = default(T);
            _first = (_first + 1) % Data.Length;
            Size--;

            if (Data.Length/Shrink >= Size && Data.Length > DefaultCapacity)
                Resize(Data.Length/ScaleFactor);

            return value;
        }

        private void Resize(int capacity)
        {
            var arr = new T[capacity];
            for (int i = 0; i < Size; i++)
            {
                int idx = (_first + i) % Data.Length;
                arr[i] = Data[idx];
            }

            _first = 0;
            Data = arr;
        }

        #endregion
    }
}

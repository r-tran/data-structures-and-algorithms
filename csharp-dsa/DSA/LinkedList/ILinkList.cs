using System.Collections.Generic;

namespace DSA.LinkedList
{
    public interface ILinkList<T> : IEnumerable<T>
    {
        #region Properties               
        int Size { get; }

        bool IsEmpty { get; }

        T Front { get; }

        T Back { get;  }
        #endregion

        #region Methods                   
        T ValueAt(int index);

        void PushFront(T value);

        T PopFront();

        void PushBack(T value);

        T PopBack();

        void Insert(int index, T value);

        void Erase(int index);

        T ValueNFromEnd(int n);

        void Reverse();

        void RemoveValue(T value);
        #endregion
    }
}

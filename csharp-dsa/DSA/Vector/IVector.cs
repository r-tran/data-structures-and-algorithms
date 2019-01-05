using System.Collections.Generic;

namespace DSA.Vector
{
    public interface IVector<T> : IEnumerable<T>
    {
        #region Properties
        int Size { get; }

        int Capacity { get; }

        bool IsEmpty { get; }
        #endregion

        #region Methods
        T At(int index);

        void PushBack(T item);

        void Insert(int index, T item);

        void Prepend(T item);

        T Pop();

        void Delete(int index);

        void Remove(T item);

        int Find(T item);
        #endregion
    }
}
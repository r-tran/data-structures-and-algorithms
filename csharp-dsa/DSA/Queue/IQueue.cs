using System.Collections.Generic;

namespace DSA.Queue
{
    public interface IQueue<T>
    {
        bool IsEmpty { get; }                

        int Size { get; }

        T Front { get; }

        void Enqueue(T element);

        T Dequeue();                      
    }
}

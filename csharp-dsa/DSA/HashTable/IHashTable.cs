using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace DSA.HashTable
{
    public interface IHashTable<TKey, TValue> : IEnumerable<TKey>
    {
        void Add(TKey key, TValue value);

        void RemoveKey(TKey key);

        bool Exists(TKey key);
        
        TValue this[TKey key] { get; set; }

        int Hash(TKey key);

        int Size { get; }

        int Capacity { get; }

    }
}

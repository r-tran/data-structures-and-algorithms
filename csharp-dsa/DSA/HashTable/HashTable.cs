using System;
using System.CodeDom;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DSA.HashTable
{
    public class HashTable<TKey, TValue> : IHashTable<TKey, TValue>
    {
        private const int DefaultCapacity = 11;
        private static readonly Random _rand = new Random();
        private const int MadPrime = 109345121;
        private readonly int MadScale;
        private readonly int MadShift;

        private Item<TKey, TValue>[] _items;

        public int Size { get; private set; }

        public int Capacity { get; private set; }

        public float LoadFactor => (float) Size/Capacity;

        public TValue this[TKey key]
        {
            get
            {
                var index = Hash(key);
                while (!IsAvailable(_items[index]))
                {
                    if (EqualityComparer<TKey>.Default.Equals(_items[index].Key, key))
                        return _items[index].Value;

                    index = (index + 1)%Capacity;
                }

                throw new KeyNotFoundException();
            }

            set
            {
                Add(key, value);
            }
        }                        

        public HashTable()
        {         
            _items = new Item<TKey, TValue>[DefaultCapacity];
            MadScale = _rand.Next(1, MadPrime);
            MadShift = _rand.Next(MadPrime);
            Size = 0;
            Capacity = DefaultCapacity;            
        }

        public void Add(TKey key, TValue value)
        {
            int index = Hash(key);
            while (!IsAvailable(_items[index]))
            {
                if (EqualityComparer<TKey>.Default.Equals(_items[index].Key, key))
                {
                    _items[index].Value = value;
                    return;
                }
                    
                index = (index + 1)%Capacity;
            }

            _items[index] = new Item<TKey, TValue>(key, value);
            Size++;
            if (LoadFactor >= 0.5)
                ResizeTable();
        }

        private void ResizeTable()
        {                 
            var olditems = _items;
            int newcapacity = Capacity *= 2;
            _items = new Item<TKey, TValue>[newcapacity];
            Capacity = newcapacity; 
            Size = 0;

            foreach (var item in olditems)
            {
                if (!IsAvailable(item))
                    Add(item.Key, item.Value);
            }
        }

        private bool IsAvailable(Item<TKey, TValue> item)
        {
            if (item == null || (item.IsSentinel == true && item.Key == null))
                return true;
            return false; 
        }

        public bool Exists(TKey key)
        {
            try
            {
                var found = this[key];
                return true;
            }
            catch (KeyNotFoundException ex)
            {
                return false;
            }
        }               

        /// <summary>
        /// Hash function using Multiply-Add-and-Divide function. 
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public int Hash(TKey key)
        {
            return (int) ((((uint) key.GetHashCode() * MadScale) + MadShift) % MadPrime) % Capacity;     
        }

        public void RemoveKey(TKey key)
        {
            int index = Hash(key);
            while (!IsAvailable(_items[index]))
            {
                if (EqualityComparer<TKey>.Default.Equals(_items[index].Key, key))
                {
                    _items[index].Key = default(TKey);
                    _items[index].Value = default(TValue);
                    _items[index].IsSentinel = true;
                    Size--;
                    return;
                }

                index = (index + 1)%Capacity;
            }

            throw new KeyNotFoundException();
        }

        public void PrintTable()
        {
            foreach (var item in _items)
            {
                if (item != null)
                {
                    Console.WriteLine($"Key:'{item.Key}' Value:'{item.Value}'");
                }
            }

        }

        public IEnumerator<TKey> GetEnumerator()
        {
            foreach (var item in _items)
            {
                if (!IsAvailable(item))
                    yield return item.Key;
            }
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }
}

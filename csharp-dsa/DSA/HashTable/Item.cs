using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DSA.HashTable
{
    internal class Item<TKey, TValue> : IItem
    {
        internal TKey Key { get; set; }       
        internal TValue Value { get; set; }
        internal bool IsSentinel { get; set; }

        public Item(TKey key, TValue value)
        {
            Key = key;
            Value = value;
            IsSentinel = false;            
        }
    }

    internal class DummyItem : IItem
    {       
    }

    internal interface IItem
    {
    }
}

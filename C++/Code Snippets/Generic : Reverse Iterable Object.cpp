template <typename Type>
Type reverse(const Type& iterObj)  //Any iterable rvalue
{
    Type reversed = iterObj;         //A copy of the item
    size_t size = iterObj.size();   //Reduces code clutter

    for(int i=0; i < (size / 2); i++)
    {
        swap(reversed[i], reversed[size-1-i]);
    }

    return reversed;
}

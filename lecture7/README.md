<div align = "center"> 

# Lecture 7
## Pointers 2 

</div>


> [!important]
> - Safe printer
>   - Calling pointers into functions
>   - 'delete' 'new'
>   - (-> what does this do) this access struct/class's attributes using pointers: pointerName -> classAttributename. * is whole object, -> is specific
>   - smart pointers (unique pointer) -> (auto)
>   - *cmp(int, int) = &greaterthan (function)
>   - double pointer
>   - association vs containment
>   - leaking dangling pointer
>   - double delete
>   - this (what does it do) points to the current object. Consider alice.____, the current object is alice 

```C++
void triple(vector<int*>& v> {
  for (int* p : v) {
    *p *= 3
  }
}

for (int* p: v) delete p; // study (freeing the heap aka memory) 
```




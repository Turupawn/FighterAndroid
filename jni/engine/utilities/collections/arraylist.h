

#ifndef _GE_ARRAYLIST_
#define _GE_ARRAYLIST_

template <class T> 
class arraylist
{
public:

	arraylist()
	{
	  arr=0;
      size=0;
	}
	~arraylist()
	{
	  clear();
	}

	void pushBack(T value)
	{
		T * temp = new T[size+1];
		temp[size] = value;
		if(arr!=0)
		{
			memcpy(temp,arr,size*sizeof(T));
			delete [] arr;
		}
		arr=temp;
		size++;
	}

	void clear()
	{
		if(arr)
		  delete []arr;
          
	    size=0;
	}

	void removeAt(unsigned int pos)
	{
		T * temp = new T[size-1];
	    memcpy(temp,arr,pos*sizeof(T));
		memcpy(temp+pos,arr+(pos+1),(size-(pos+1))*sizeof(T));
		delete arr;
		arr=temp;
		size--;
	}

	T operator [](unsigned int pos)
	{
		return arr[pos];
	}

	unsigned int getSize()
	{
       return size;
	}

private:

	T *arr;
	unsigned int size;

};


#endif

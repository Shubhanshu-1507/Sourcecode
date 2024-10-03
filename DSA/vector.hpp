template <class T> class vector {
private:
  T *arr = '\0';
  int curr_size;
  int capacity;

public:
  vector() {
    curr_size = 0;
    capacity = 0;
  }
  vector(int size, T initial) {
    arr = new T[curr_size];
    for (int i = 0; i < size; i++) {
      arr[i] = initial;
    }
    this->curr_size = size;
    this->capacity = size;
  }
  vector(int size){
      arr = new T[size];
      for(int i = 0;i<size;i++){
        arr[i] = 0;
      }
      curr_size = size;
      capacity = size;
  }
  void resize(int newSize) {
    T *newArr = new T[newSize];
    for (int i = 0; i < curr_size; i++) {
      newArr[i] = arr[i];
    }
    if (this->arr != 0)
      delete[] this->arr;
    this->arr = newArr;
    this->capacity = newSize;
  }
  void push_back(T data) {
    if (capacity == 0)
      this->resize(1);
    else if (curr_size >= capacity)
      this->resize(2 * curr_size);
    arr[curr_size++] = data;
  }
  T front() {
    if (curr_size > 0)
      return arr[0];
    return 0;
  }
  T back() {
    if (curr_size > 0) {
      return arr[curr_size - 1];
    }
    return 0;
  }
  int size() { return this->curr_size; }
  int Capacity() { return capacity; }
  T operator[](int index) {
    if (index < curr_size)
      return arr[index];
    return 0;
  }
  T* begin(){
      return arr;
  }
  T* end(){
      return arr+curr_size;
  }
};

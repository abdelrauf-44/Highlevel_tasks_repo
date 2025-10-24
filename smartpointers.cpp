#include<iostream> 
#include<memory>


using namespace std; 


class myClass{
    public:
    myClass(){
        cout<<"Constructor called!"<<endl;
    }
    ~myClass(){
        cout<<"Destructor called!"<<endl;
    }
};





int main(){

    unique_ptr<myClass> ptr1 = make_unique<myClass>(); // unique_ptr that exclusively owns a myClass object

    shared_ptr<myClass> ptr2 = make_shared<myClass>(); // shared_ptr that can be shared among multiple pointers

    

    weak_ptr<myClass>wptr; // weak_ptr that holds a non-owning reference to a myClass object managed by shared_ptr
{
    shared_ptr<myClass> ptr4 = make_shared<myClass>(); // another shared_ptr managing a new myClass object


    wptr = ptr4; // Create a weak_ptr from a shared_ptr

}

    if (!wptr.expired()) {      // Check if the object managed by the weak_ptr is still alive
        cout << "The object is still alive." << endl;
    } else {
        cout << "The object has been destroyed." << endl; // ptr4 has gone out of scope, so the object is destroyed
    }

    cout << "counter of shared_ptr: " << ptr2.use_count() << endl; // prints the number of shared_ptr instances managing the same object
{
    shared_ptr<myClass> ptr3 = ptr2; // now ptr2 and ptr3 share ownership of the same object

    cout << "counter of shared_ptr after copy: " << ptr2.use_count() << endl; // prints the updated count
} // ptr3 goes out of scope here, and the reference count is decremented

    cout << "counter of shared_ptr after ptr3 goes out of scope: " << ptr2.use_count() << endl; // prints the count after ptr3 is out of scope


    return 0;

}

/*
unique_ptr: A unique_ptr is a smart pointer that owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope. It cannot be copied, only moved, ensuring that there is only one unique_ptr pointing to a given resource at any time.

it constructed with class and destructor called when it goes out of scope.

note: unique_ptr cannot be copied, so the following line would cause a compilation error:
    unique_ptr<myClass> ptr2 = ptr1; // Error: cannot copy unique_ptr
notes: To transfer ownership of the managed object from one unique_ptr to another, you can use the std::move function:
    unique_ptr<myClass> ptr2 = move(ptr1); // Transfer ownership from ptr1 to ptr2

shared_ptr: A shared_ptr is a smart pointer that retains shared ownership of an object through a pointer. Multiple shared_ptr instances can own the same object. The object is destroyed when the last remaining shared_ptr owning the object is destroyed or reset.

its also constructed with class and destructor called when the last shared_ptr goes out of scope.

 notes: You can check how many shared_ptr instances share ownership of the same object using the use_count() method:
    cout << "Number of owners: " << ptr2.use_count() << endl;

    notes: When a shared_ptr is copied, the reference count is incremented. When a shared_ptr is destroyed or reset, the reference count is decremented.
    When the reference count reaches zero, the managed object is deleted.


weak_ptr: A weak_ptr is a smart pointer that holds a non-owning reference to an object managed by a shared_ptr. 
It does not affect the reference count of the shared_ptr, and it can be used to break circular references between shared_ptr instances.

notes: 
You can create a weak_ptr from a shared_ptr:
    weak_ptr<myClass> wptr = ptr4; // Create a weak_ptr from a shared_ptr
You can check if the object managed by the weak_ptr is still alive using the expired() method:
    if (!wptr.expired()) {
        cout << "The object is still alive." << endl;
    } else {
        cout << "The object has been destroyed." << endl;
    }

    notes: To access the object managed by a weak_ptr, you need to convert it to a shared_ptr using the lock() method:
    shared_ptr<myClass> sptr = wptr.lock();

*/

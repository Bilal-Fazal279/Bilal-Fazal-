#include <iostream>
using namespace std;
class Node
{
private:
    string name;
    int id;
    int quantity;
    double price;
    Node *next;

public:
    string getName()
    {
        return name;
    }
    int getid()
    {
        return id;
    }
    int getQuantity()
    {
        return quantity;
    }
    double getPrice()
    {
        return price;
    }
    Node *getNext()
    {
        return next;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setQuantity(int quantity)
    {
        this->quantity = quantity;
    }
    void setPrice(double price)
    {
        this->price = price;
    }
    void setNext(Node *next)
    {
        this->next = next;
    }
};

class Inventory
{
private:
    Node *head;
public:
    Inventory()
    {
        head = new Node;
        head->setNext(NULL);
    }
    void addProduct(string name, int id, int quantity, double price)
    {
    	
        Node *newProduct = new Node();
        newProduct->setName(name);
        newProduct->setId(id);
        newProduct->setQuantity(quantity);
        newProduct->setPrice(price);
        newProduct->setNext(NULL);

            Node *pointerNode = head;
            while (pointerNode->getNext() != NULL)
            {
                pointerNode = pointerNode->getNext();
            }
            pointerNode->setNext(newProduct);
        
        cout << "Product added sucessfully " << endl;
    }
    void removeProduct(int id)
    {

        if (head->getid() == id)
        {
            Node *pointerNode = head;
            head = head->getNext();
            delete pointerNode;
            cout<<"Product Removed successfully "<<endl;
        }
        else{
            Node *lastpointer = head;
            Node *pointer = head->getNext();
            while (pointer->getNext() !=  NULL)
            {
                if (pointer->getid() == id)
                {
                    lastpointer->setNext(pointer->getNext());
                delete pointer;
				cout<<"Product Removed successfully "<<endl;
                break;    
                }
                lastpointer = pointer;
                pointer = pointer -> getNext();
            }
            
        }

    }

    void updateProduct(int id, int quantity, double price){
        Node *ptr =head;
        while (ptr != NULL)
        {
            if (ptr -> getid() == id)
            {
                ptr -> setQuantity(quantity);
                ptr -> setPrice(price);
                cout<<"Product updated successfully "<<endl;
            }
            ptr = ptr -> getNext();
        }
        
    }
    void displayInventory()
    {
        cout<<" Inventory:"<<endl;
		cout<<"Name \tID \tQuantity \tPrice "<<endl;
        Node *pointer = head;
        while (pointer->getNext() != NULL)
        {
        	pointer = pointer -> getNext();
            
			cout<<pointer -> getName()<<"\t"<<pointer->getid()<<"\t"<<pointer->getQuantity()<<"\t \t"<<pointer->getPrice()<<endl;
        }
        
    }
};
int main()
{
    Inventory obj;
    start_point:
    int choice,id,quantity,number_of_products;
    double price;
    string name;
    cout<<"Please choose an Action: "<<endl;
    cout<<"1.  Add Product "<<endl;
    cout<<"2.  Remove Product "<<endl;
    cout<<"3.  Update Product "<<endl;
    cout<<"4.  Display Inventory "<<endl;
    cout<<"0.  Exit "<<endl;
    cout<<"Enter your choice:  ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"How many products do you want to add? ";
        cin>>number_of_products;
        for (int i = 1; i <= number_of_products; i++)
        {
        	cout<<"Enter Product Name:  ";
            cin>>name;
            cout<<"Enter Product ID:  ";
            cin>>id;
            cout<<"Enter Product Quantity:  ";
            cin>>quantity;
            cout<<"Enter Product Price:  ";
            cin>>price;
            obj.addProduct(name,id,quantity,price);
        }
        break;
    case 2:
            cout<<"Enter Product ID to remove: ";
            cin>>id;
            obj.removeProduct(id);
            break;
    case 3:
            cout<<"Enter Product ID to update: ";
            cin>>id;
            cout<<"Enter New Quantity: ";
            cin>>quantity;
            cout<<"Enter New Price: ";
            cin>>price;
            obj.updateProduct(id,quantity,price);
            break;
    case 4:
            obj.displayInventory();
            break;
    case 0:
            exit(0);
    default:
            cout<<"Invalid Choice ";
    }
        goto start_point;
    
    
        return 0;
}

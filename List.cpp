#include <iostream>

template <class T>
List<T>::List()
{
    First = new Node<T>();
    First->Next = Last; //Set next pointer of First to Last element when nothing is in the list.
    First->changeIndex(-1); //First's index will be -1.
}

template <class T>
List<T>::List(const List & L)
{
    Node<T>* Temp;
    this->First = new Node<T>(NULL);
    this->First->changeIndex(-1);
    for (int i = 0; i <= L.last_node_index; i++)
    {
        Temp = new Node<T>(L[i]->Object); //Temp will be a new Node with the same object as in L.
        this->add(Temp, i);
    }
}

template <class T>
List<T>::~List()
{
    Node<T> *Temp, *_Next;
    if (Last != nullptr && First != nullptr)
    {
        Temp = First;
        do
        {
            _Next = Temp->Next;
            delete Temp;
            Temp = _Next;
        } while (Temp != nullptr);
    }
}

template <class T>
void List<T>::add(Node<T>* Added, int index) //Works good for index = 0 and index = last_node_index;
{
    clock_t start, stop;
    double t; //time of initiation of the node
    try {
        if (index<0 || index >last_node_index + 1)
            throw string("Invalid index number!");
    }
    catch (string err)
    {
        cout << err << endl;
    }

    start = clock();
    if (index == 0)
    {
        Added->Next = First->Next;
        First->Next = Added;
        Added->changeIndex(0);
        Node<T>* Temp = Added->Next;
        if (Temp != NULL) {
            for (int i = Added->Next->getIndex(); i <= last_node_index + 1; i++)
            {
                Temp->changeIndex(i + 1);
                Temp = Temp->Next;
            }
        }
        stop = clock();
        double t = ( (double)(stop - start) / CLOCKS_PER_SEC )* 1000; // Calculating the time in miliseconds
        Added->changeTime(t);
    }

    else
    {
        Node<T> *Temp;
        Temp = this->operator[](index - 1); //set this to the index - 1
        Added->Next = Temp->Next; //It works fine even when Temp is nullptr
        Temp->Next = Added;
        Added->changeIndex(index); //Set the index of added element

        Temp = Added->Next;
        while (Temp != NULL)
        {
            Temp->changeIndex(Temp->getIndex() + 1); //Increase index of element in the list
            Temp = Temp->Next;
        }


        stop = clock();
        t = ( (double)(stop - start) / CLOCKS_PER_SEC )* 1000; // Calculating the time
        Added->changeTime(t); //Change the time of creating the Node
    }
    last_node_index++; //Increase last_node_index, because we added one to list

}

template <class T>
void List<T>::deleteNode(int deleted_index)
{
    try {
        if (deleted_index<0 || deleted_index >last_node_index + 1)
            throw string("Invalid index number!");
    }
    catch (string err)
    {
        cout << err << endl;
    }

    Node<T>* Temp = this->operator[](deleted_index);
    if (deleted_index == 0) //If deleteNode is the first one, we just delete it.
    {
        First->Next = Temp->Next; //But before we do, we set First->Next as next of Temp.
        delete Temp;
        Temp = First->Next;
        int i = 0;
        while (Temp != NULL)
        {
            Temp->changeIndex(i);
            i++;
            Temp = Temp->Next;
        }
    }
    else
    {
        Node<T> *Temp, *Deleted;
        Temp = this->operator[](deleted_index - 1); //Set the Prev Node to the deletedNode.
        Deleted = Temp->Next; //Remember Temp->Next
        Temp->Next = Deleted->Next; //Switch Nodes
        delete Deleted; //Delete Deleted Node.
        Temp = Temp->Next; //Set Temp to next, which index is actually deleted_index + 1
        int i = deleted_index;
        while (Temp != NULL)
        {
            Temp->changeIndex(i);
            Temp = Temp->Next;
            i++;
        }
    }
    last_node_index--; //Decrease last node index.
}

template <class T>
void List<T>::show()
{
    Node<T>* Temp;
    for (int i = 0; i <= last_node_index; i++)
    {
        Temp = this->operator[](i);
        if (Temp != NULL)
            cout << i << ". " << Temp->Object->getName() << endl;
        else
            cout << "NULL" << endl;
    }
}

template<class T>
List<T> & List<T>::operator=(const List<T> & L)
{
    Node<T>* Temp;
    this->First->changeIndex(-1);
    for (int i = 0; i <= L.last_node_index; i++)
    {
        Temp = new Node<T>(L[i]->Object); //Temp will be a new Node with the same object as in L.
        this->add(Temp, i); //Add Temp object to new List.
    }
    return *this;
}

template <class T>
Node<T>* List<T>::operator[](int index) const
{
    Node<T>* Temp;
    Temp = First;
    try {
        if (index<0 || index >last_node_index)
            throw string("Wrong index number!");
    }
    catch (string err)
    {
        std::cout << err << endl;
    }

    for (int i = 0; i <= last_node_index; i++) //Go through every node and find if one of them has got this index number
    {
        if (Temp != nullptr)
        {
            if (Temp->getIndex() == index)
                break;
            else Temp = Temp->Next;
        }
        else
        {
            if (Temp = First)
                return First;
            else if (Temp = Last)
                return Last;
            else
                return nullptr;
        }
    }
    return Temp;
}

template <class T>
int List<T>::getLastNodeIndex()
{
    return last_node_index;
}

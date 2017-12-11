  #include <bits/stdc++.h>

  using namespace std;

  typedef struct node
  {
    int data;
    node* next;
  }node;

  void printll(node* head){
    int count = 0;
    while(head != NULL){
      cout << head->data << " ";
      head = head->next;
      count++;
    }
    cout << "\n";
    cout << "number of nodes " << count << "\n";
  }

  node* createNode(int x){
    node* temp;
    temp = (node*)malloc(sizeof(node));

    temp->data = x;
    temp->next = NULL;
    return temp;
  }

  void appendNode(node** head, node* new_node){
    node* temp;
    if(*head == NULL){
      *head = new_node;
    }
    temp = *head;
    while(temp->next!= NULL){
      temp = temp->next;
    }
    temp->next = new_node;
  }

  void sortedInsert(node** head, node* new_node){
    node* temp;
    node* temp1;
    if(*head == NULL || (*head)->data >= new_node->data){
      new_node->next = *head;
      *head = new_node;
    }
    else
    {
      temp = *head;
      while(temp->next!= NULL && temp->next->data < new_node->data){
        temp = temp->next;
      }
      temp1 = temp->next;
      temp->next = new_node;
      new_node->next = temp1;
    }
  }

  int getMid(node **head){
      node *temp = *head, *temp1 = *head;
      if(*head == NULL){
        return -999;
      }

      else{
        while(temp1->next!=NULL){
          temp = temp->next;
          temp1 = temp1->next->next;
          if(temp1 == NULL){
            return temp->data;
          }
        }
        return temp->data;
      }
  }

  int main()
  {
      int i;
      node* head = createNode(0);

      node* a = createNode(1);
      node* b = createNode(3);
      node* c = createNode(2);
      node* d = createNode(5);


      appendNode(&head,a);
      appendNode(&head,b);
      appendNode(&head,d);
      sortedInsert(&head,c);

      printll(head);
      std::cout << "Mid val is: " << getMid(&head) << '\n';
      std::cout << "ptr vals head lol : " << head->data << '\n';
      return 0;
  }

// ============================================================
//                    HEADER FILES
// ============================================================

#include <stdio.h>
#include <stdlib.h>


// ============================================================
//                    NODE STRUCTURE
// ============================================================

struct node
{
   int data;
   struct node *next;
};


// ============================================================
//                    GLOBAL POINTERS
// ============================================================

struct node *start = NULL;
struct node *stop = NULL;
struct node *new_node;
struct node *preptr;
struct node *ptr;
struct node *temp;


// ============================================================
//                    FUNCTION PROTOTYPES
// ============================================================

void insert_begin(void);
void insert_end(void);
void insert_before_node(void);
void insert_after_node(void);

void delete_begin(void);
void delete_end(void);
void delete_before_node(void);
void delete_specific_node(void);
void delete_after_node(void);

void replace_node(void);
void search_node(void);
void count_node(void);
void display(void);


// ============================================================
//                    MAIN FUNCTION
// ============================================================

int main()
{
   int choice;

   while (1)
   {
      // ---------------- MENU ----------------

      printf("1. Insert at starting of a LINNKED LIST.\n");
      printf("2. Insert at the end of a LINNKED LIST.\n");
      printf("3. Insert before a node of a LINNKED LIST.\n");
      printf("4. Insert after a node of a LINNKED LIST.\n");
      printf("5. View the LINKED LIST\n");
      printf("6. Search an element in a LINKED LIST\n");
      printf("7. Count total number of Node in a LINKED LIST\n");
      printf("8. Delete at starting of a LINKED LIST.\n");
      printf("9. Delete at the end of a LINKED LIST.\n");
      printf("10. Delete before a node of a LINKED LIST.\n");
      printf("11. Delete at specified node of a LINKED LIST.\n");
      printf("12. Delete after a node of a LINKED LIST.\n");
      printf("13. Replace a node with speicified node.\n");
      printf("14. Exit\n");

      printf("\n\nEnter your choice :  ");
      scanf("%d",&choice);


      // ---------------- MENU OPERATIONS ----------------

      switch (choice)
      {
         case 1 :
         {
            insert_begin();
            break;
         }

         case 2 :
         {
            insert_end();
            break;
         }

         case 3 :
         {
            insert_before_node();
            break;
         }

         case 4 :
         {
            insert_after_node();
            break;
         }

         case 5 :
         {
            display();
            break;
         }

         case 6 :
         {
            search_node();
            break;
         }

         case 7 :
         {
            count_node();
            break;
         }

         case 8 :
         {
            delete_begin();
            break;
         }

         case 9 :
         {
            delete_end();
            break;
         }

         case 10 :
         {
            delete_before_node();
            break;
         }

         case 11 :
         {
            delete_specific_node();
            break;
         }

         case 12 :
         {
            delete_after_node();
            break;
         }

         case 13 :
         {
            replace_node();
            break;
         }

         case 14 :
         {
            // Free all dynamically allocated nodes before exit

            ptr = start;

            while (ptr != NULL)
            {
               temp = ptr->next;    // Store address of next node
               free(ptr);           // Free current node
               ptr = temp;          // Move to next node
            }

            start = NULL;
            stop = NULL;

            printf("All dynamically allocated memory freed successfully.\n");
            printf("Program Ended Successfully.\n\n\n");

            return 0;
         }

         default :
         {
            printf("Invalid Choice. Enter correct choice.\n\n");
            break;
         }
      }
   }
}


// ============================================================
//              INSERT NODE AT BEGINNING
// ============================================================

void insert_begin(void)
{
   // Allocate memory for new node

   new_node = malloc(sizeof(struct node));

   if(new_node == NULL)
   {
      printf("Memory alllocation is failed !!\n\n");
      return;
   }

   printf("Enter Data :  ");
   scanf("%d",&new_node->data);


   // If linked list is empty

   if (start == NULL)
   {
      start = new_node;
      stop = new_node;
      new_node->next = NULL;

      printf("Data %d is successfully inserted.\n",new_node->data);

      return;
   }


   // Insert new node before current first node

   new_node->next = start;
   start = new_node;

   printf("Data %d is successfully inserted.\n",new_node->data);
}


// ============================================================
//                 INSERT NODE AT END
// ============================================================

void insert_end(void)
{
   // Allocate memory for new node

   new_node = malloc(sizeof(struct node));

   if (new_node == NULL)
   {
      printf("Memory Allocation is failed !!\n\n");
      return;
   }

   printf("Enter Data :  ");
   scanf("%d",&new_node->data);

   printf("Data %d is successfully inserted.\n",new_node->data);


   // If linked list is empty

   if (start == NULL)
   {
      start = new_node;
      stop = new_node;
      new_node->next = NULL;

      return;
   }


   // Attach new node after current last node

   stop->next = new_node;
   new_node->next = NULL;
   stop = new_node;
}


// ============================================================
//              INSERT BEFORE A SPECIFIC NODE
// ============================================================

void insert_before_node(void)
{
   if (start == NULL)
   {
      printf("List is empty.\n\n");
      return;
   }

   int node;

   printf("Enter data of that node before it new node want to insert :  ");
   scanf("%d",&node);


   // If new node has to be inserted before first node

   if (start->data == node)
   {
      new_node = malloc(sizeof(struct node));

      if (new_node == NULL)
      {
         printf("Memory allocation is failed !!\n\n");
         return;
      }

      printf("Enter Data of New Node:  ");
      scanf("%d",&new_node->data);

      ptr = start;
      new_node->next = ptr;
      start = new_node;

      printf("Data %d inserted successfully.\n\n",new_node->data);

      return;
   }


   // Search for the specified node

   ptr = start;
   preptr = ptr;

   while (ptr != NULL && ptr->data != node)
   {
      preptr = ptr;
      ptr = ptr->next;

      if (ptr == NULL)
      {
         printf("Yor given node %d is not found.\n\n",node);
         return;
      }
   }


   // Allocate and insert new node before ptr

   new_node = malloc(sizeof(struct node));

   if (new_node == NULL)
   {
      printf("Memory allocation is failed !!\n\n");
      return;
   }

   printf("Enter Data of New Node:  ");
   scanf("%d",&new_node->data);

   preptr->next = new_node;
   new_node->next = ptr;

   printf("Data %d inserted successfully.\n\n",new_node->data);
}


// ============================================================
//               INSERT AFTER A SPECIFIC NODE
// ============================================================

void insert_after_node(void)
{
   if (start == NULL)
   {
      printf("LIST is empty.\n\n");
      return;
   }

   int node;

   printf("Enter Data of That Node after that New Node want to Insert : ");
   scanf("%d", &node);


   // Search for the specified node

   ptr = start;

   while (ptr != NULL && ptr->data != node)
   {
      ptr = ptr->next;
   }

   if (ptr == NULL)
   {
      printf("Your given Node %d is not found in the List.\n\n", node);
      return;
   }


   // Allocate memory for new node

   new_node = malloc(sizeof(struct node));

   if (new_node == NULL)
   {
      printf("Memory allocation is failed !!\n\n");
      return;
   }

   printf("Enter Data of New Node : ");
   scanf("%d", &new_node->data);


   // Insert new node after specified node

   new_node->next = ptr->next;
   ptr->next = new_node;


   // Update stop if insertion occurs at end

   if (ptr == stop)
   {
      stop = new_node;
   }

   printf("Data %d inserted successfully.\n\n", new_node->data);
}


// ============================================================
//                    DISPLAY LINKED LIST
// ============================================================

void display(void)
{
   if (start == NULL)
   {
      printf("LINKED LIST is empty.\n\n");
      return;
   }

   ptr = start;

   while(ptr != NULL)
   {
      printf("%d -> ",ptr->data);
      ptr = ptr->next;
   }

   printf("NULL\n\n");
}


// ============================================================
//                 DELETE NODE FROM BEGINNING
// ============================================================

void delete_begin(void)
{
   if (start == NULL)
   {
      printf("LIST is empty.\n\n");
      return;
   }

   ptr = start;
   start = start->next;

   printf("Node %d is deleted successfully.\n\n",ptr->data);

   free(ptr);


   // If the last remaining node was deleted

   if (start == NULL)
   {
      stop = NULL;
   }
}


// ============================================================
//                    DELETE NODE FROM END
// ============================================================

void delete_end(void)
{
   if (start == NULL)
   {
      printf("LIST is empty.\n\n");
      return;
   }


   // If only one node exists

   if (start == stop)
   {
      printf("Data %d is deleted successfully.\n\n",start->data);

      free(start);

      start = NULL;
      stop = NULL;

      return;
   }


   // Traverse to the last node

   preptr = start;
   ptr = start;

   while(ptr->next != NULL)
   {
      preptr = ptr;
      ptr = ptr->next;
   }


   // Remove last node

   printf("Node %d is deleted successfully.\n\n",ptr->data);

   stop = preptr;
   preptr->next = NULL;

   free(ptr);
}


// ============================================================
//              DELETE BEFORE A SPECIFIC NODE
// ============================================================

void delete_before_node(void)
{
   if (start == NULL)
   {
      printf("Linked List is Empty.\n\n");
      return;
   }

   int num;

   printf("Enter node before which you want to delete : ");
   scanf("%d", &num);


   // No node exists before the first node

   if (start->data == num)
   {
      printf("There is no node before %d.\n\n", num);
      return;
   }


   // Only one node exists

   if (start->next == NULL)
   {
      printf("Node %d not found.\n\n", num);
      return;
   }


   // Delete first node when target is second node

   if (start->next->data == num)
   {
      temp = start;
      start = start->next;

      printf("Node %d is deleted successfully.\n\n", temp->data);

      free(temp);

      return;
   }


   // Maintain three pointers during traversal

   preptr = start;
   temp = start->next;
   ptr = temp->next;

   while (ptr != NULL && ptr->data != num)
   {
      preptr = temp;
      temp = ptr;
      ptr = ptr->next;
   }

   if (ptr == NULL)
   {
      printf("Node %d not found.\n\n", num);
      return;
   }


   // Bypass and delete the node before target

   preptr->next = ptr;

   printf("Node %d is deleted successfully.\n\n", temp->data);

   free(temp);
}


// ============================================================
//                 DELETE A SPECIFIC NODE
// ============================================================

void delete_specific_node(void)
{
   if (start == NULL)
   {
      printf("LIST is empty.\n\n");
      return;
   }

   int num;

   printf("Enter data of that particular node to be delete : ");
   scanf("%d",&num);


   // If first node has to be deleted

   if (start->data == num)
   {
      delete_begin();
      return;
   }


   // Search for the specified node

   preptr = start;
   ptr = start->next;

   while (ptr != NULL && ptr->data != num)
   {
      preptr = ptr;
      ptr = ptr->next;
   }

   if (ptr == NULL)
   {
      printf("Data not found in the list.\n\n");
      return;
   }


   // Bypass the node

   preptr->next = ptr->next;


   // Update stop if last node is deleted

   if (ptr == stop)
   {
      stop = preptr;
   }

   printf("Node %d deleted successfully.\n\n",ptr->data);

   free(ptr);
}


// ============================================================
//                DELETE AFTER A SPECIFIC NODE
// ============================================================

void delete_after_node(void)
{
   if (start == NULL)
   {
      printf("Linked List is empty.\n\n");
      return;
   }

   int num;

   printf("Enter node after which node you want to delete : ");
   scanf("%d", &num);


   // Search for the specified node

   preptr = start;

   while (preptr != NULL && preptr->data != num)
   {
      preptr = preptr->next;
   }

   if (preptr == NULL)
   {
      printf("Data %d is not found.\n\n", num);
      return;
   }


   // No node exists after the last node

   if (preptr->next == NULL)
   {
      printf("There is no node after %d.\n\n", num);
      return;
   }


   // Store and bypass the node to be deleted

   temp = preptr->next;
   preptr->next = temp->next;


   // Update stop if last node is deleted

   if (temp == stop)
   {
      stop = preptr;
   }

   printf("Node %d is deleted successfully.\n\n", temp->data);

   free(temp);
}


// ============================================================
//                  REPLACE NODE DATA
// ============================================================

void replace_node(void)
{
   if (start == NULL)
   {
      printf("Linked List is empty.\n\n");
      return;
   }

   int node;

   printf("Enter Data Node that want to replace :  ");
   scanf("%d",&node);

   ptr = start;


   // Search for node to be replaced

   while (ptr != NULL)
   {
      if (ptr->data == node)
      {
         int new_data;

         printf("Enter Data of New Node :  ");
         scanf("%d",&new_data);


         // Replace old data with new data

         ptr->data = new_data;

         printf("Data %d is replaced successfully with %d new Data.\n\n",
                node, ptr->data);

         return;
      }

      ptr = ptr->next;
   }

   printf("Your given Node %d is not not found. Please Enter the correct Node.\n\n",
          node);
}


// ============================================================
//                    SEARCH A NODE
// ============================================================

void search_node(void)
{
   if (start == NULL)
   {
      printf("LIST is empty.\n\n");
      return;
   }

   int num;

   ptr = start;

   printf("Enter a number to be search in a LIST :  ");
   scanf("%d",&num);


   // Traverse until data is found

   while (ptr != NULL)
   {
      if (ptr->data == num)
      {
         printf("Data is Found.\n\n");
         return;
      }

      ptr = ptr->next;
   }

   printf("Data is not Found.\n\n");
}


// ============================================================
//                  COUNT TOTAL NODES
// ============================================================

void count_node(void)
{
   if (start == NULL)
   {
      printf("LIST is empty.\n\n");
      return;
   }

   int count = 0;

   ptr = start;


   // Traverse and count each node

   while(ptr != NULL)
   {
      count++;
      ptr = ptr->next;
   }

   printf("Total nodes :  %d\n\n",count);
}



#include "node.h"
#include <string.h>
#include <iostream>
using namespace std;

char *replaceWord(const char *s, const char *oldW,
                  const char *newW)
{
  char *result;
  int i, cnt = 0;
  int newWlen = strlen(newW);
  int oldWlen = strlen(oldW);

  // Counting the number of times old word
  // occur in the string
  for (i = 0; s[i] != '\0'; i++)
  {
    if (strstr(&s[i], oldW) == &s[i])
    {
      cnt++;

      // Jumping to index after the old word.
      i += oldWlen - 1;
    }
  }

  // Making new string of enough length
  result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1);

  i = 0;
  while (*s)
  {
    // compare the substring with the result
    if (strstr(s, oldW) == s)
    {
      strcpy(&result[i], newW);
      i += newWlen;
      s += oldWlen;
    }
    else
      result[i++] = *s++;
  }

  result[i] = '\0';
  return result;
}

class linked_list
{
private:
  node *head, *tail;

public:
  node *currentNode;

  linked_list()
  {
    head = NULL;
    tail = NULL;
    currentNode = head;
  }
  ~linked_list()
  {
    node *temp;
    while (head)
    {
      temp = head->next;
      delete head;
      head = temp;
    }
  }
  linked_list(const linked_list &list)
  {
    head = list.head;
    tail = list.tail;
    currentNode = tail;
  }

  void add_node(char const *data)
  {
    node *tmp = new node;
    tmp->data = data;
    tmp->next = NULL;

    if (head == NULL)
    {
      head = tmp;
      currentNode = head;
      tail = tmp;
    }
    else
    {
      tail->next = tmp;
      tail = tail->next;
    }
  }

  void show_all()
  {
    node *tmp = head;
    while (tmp != tail)
    {
      cout << tmp->data << "\n";
      tmp = tmp->next;
    }

    cout << tmp->data << "\n";
    cout << "----------\n";
  }

  void replace_all_words(char const *initial_word, char const *replace_word)
  {

    node *tmp = this->head;
    while (tmp != this->tail)
    {
      if (strstr(tmp->data, initial_word))
      {
        tmp->data = replaceWord(tmp->data, initial_word, replace_word);
      }
      tmp = tmp->next;
    }
    if (strstr(tmp->data, initial_word))
    {
      tmp->data = replaceWord(tmp->data, initial_word, replace_word);
    }
    cout << "end replacing \n";
  }
  void pop()
  {
    node *temp = head;
    while (temp->next->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = NULL;
    tail = temp;
  }

  linked_list operator=(const linked_list &l)
  {
    // head = l.head;
    // tail = l.tail;
    return *this;
  }

  linked_list &operator+=(const linked_list &l)
  {

    node *tmp = l.head;
    while (tmp != l.tail)
    {
      // cout << tmp->data << "\n";
      this->add_node(tmp->data);
      tmp = tmp->next;
    }

    this->add_node(tmp->data);

    return *this;
  }

  void operator+=(const char *data)
  {
    this->add_node(data);
  }

  node *operator++(int)
  {
    try
    {
      if ((currentNode->next) == NULL)
        throw("Something Wrong");
      else
      {
        currentNode = currentNode->next;
      }
    }
    catch (const char *message)
    {
      cout << message << "\n";
      return 0;
    }
    return currentNode;
  }

  node operator*()
  {
    return *tail;
  }

  node operator+(const linked_list &l)
  {

    linked_list main_temp;
    node *tmp = head;
    // copy this list
    while (tmp != tail)
    {
      main_temp.add_node(tmp->data);
      tmp = tmp->next;
    }
    main_temp.add_node(tmp->data);

    // start copy second list
    tmp = l.head;
    while (tmp != l.tail)
    {
      main_temp.add_node(tmp->data);
      tmp = tmp->next;
    }

    main_temp.add_node(tmp->data);

    return *main_temp;
  }

  bool operator==(const linked_list &a)
  {
    return tail->data == a.tail->data;
  }
  bool operator!=(const linked_list &a)
  {
    return tail->data != a.tail->data;
  }
};
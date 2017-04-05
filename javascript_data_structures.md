# Javascript Data Structures

In computer science, a data structure is a particular way of organizing data in a computer so that it can be used efficiently. From Wikipedia

"used efficiently" here means that according to your needs. You may need for example an organizing structure that allows very fast lookup or it could be very fast insertion or any thing related to your application.

The key thing to remember is that each data structure has it own advantages and disadvantages. There isn’t any one of them that would beat all of the others, that’s the reason why it is important to know them all.

## The complexity

If you hear about data structures, you will for sure hear about their complexity. As said before every data structure has its own advantages and disadvantages, their complexity can be seen as a way of expressing their own advantages and disadvantages easily according to a specific problem.

The complexity is expressed on 2 axes, the space and the time.

### The space

The space complexity represents the memory consumption of a data structure. As for most of the things in life, you can’t have it all, so it is with the data structures. You will generally need to trade some time for space or the other way around.

### The time

The time complexity for a data structure is in general more diverse than its space complexity.

**Several operations**

In contrary to algorithms, when you look at the time complexity for data structures you need to express it for several operations that you can do with data structures. It can be adding elements, deleting elements, accessing an element or even searching for an element.

**Dependent on data**

Something that data structure and algorithms have in common when talking about time complexity is that they are both dealing with data. When you deal with data you become dependent on them and as a result the time complexity is also dependent of the data that you received. To solve this problem we talk about 3 different time complexity.

* **The best-case complexity:** when the data looks the best
* **The worst-case complexity:** when the data looks the worst
* **The average-case complexity:** when the data looks average

### The big O notation

Is how long an algorithm takes to run depending on how long is the input, usually talking about the worst case scenario. Technical description is used to describe worst-case performance or complexity of an algorithm in space used(i.e. in memory or on disk) and execution time. 

In practice, we use Big O Notation to classify algorithms by how they respond to changes in input size, so algorithms with the same growth rate are represented with the same Big O Notation. The letter O is used because the rate of growth of a function is also called order of the function.

**O(1) and O(n)**

On this story a company in South Africa, they had two offices about 50 miles away, so they set up this little test to see if it would be faster to transfer big chunks of data over the internet with their really slow internet service or via carrier pigeon. Literally they took a bunch od USB stick. And flew it from one office to the next. The pigeon won.

Transferring data over internet takes longer and longer with how much data there is. Peagon might be really slow or fast but it always basically takes the same amount of time for a pigeon to transfer one chunk of data from one office to the next one. It just has to fly 50 miles, Its not going to take longer because that USB stick contains more data.

* **O(1):** This will be the pegeon case, O of 1, its constant time with respect to the size of the input. Doesnt take longer with more input.

**Example:**

```javascript
const getLast = (items) => {
  return items[items.length - 1];
};

console.log(getLast(["a","b","c","d"])); //-> "d"
console.log(getLast(["a","b","c","d","e","f","g"])); //-> "g"
```

You will see this on algorithms that returns an element in an already known position of an array, regardless kind or length.

* **O(n):** This is the case of the internet, Internet tranfer time is O of n. It scales linearly with respect to the amount of input.

**Example:**

```javascript
var makeRange = function(array) {
  array.forEach(function(item) {
    console.log(item);
  });
};

console.log(makeRange(["a","b","c","d"])); //-> "a" "b" "c" "d" 4 steps
console.log(makeRange(["a","b","c","d", "e"])); //-> "a" "b" "c" "d" "e" 5 steps
```

An algorithm has a linear time complexity if the time to execute the algorithm is directly proportional to the input size n. Therefore the time it will take to run the algorithm will increase proportionately as the size of input n increases.

**O(log n):** These are the holy grail of search/sort algorithms, they are usually the most efficient approach when dealing with large collections. Instead of looking through the components one by one, they split the data in chunks and discard a large amount on every iteration, usually the half.

**O(n 2):** Means the function will perform proportionally to the square of the input data size. Quadratic time complexity is best illustrated with nested for loops. Here, the array provided will be looped through twice. Once for the first loop, but for each index, the array will be looped over again by the second loop. Besides being destructively redundant, the function will take twice as much time for just one additional input.

```javascript
const buildSquareMatrix = (items) => {
  let matrix= [];
  for (let i=0, total=items.length; i < total; i++){ 
    matrix[i] = [];
    for (let j=0, total=items.length; j < total; j++)
      matrix[i].push(items[j]);
  }
  return matrix;
};

const result = buildSquareMatrix(["a","b","c"]);
console.log(result); //-> 9 steps
/* 
[["a","b","c"],
 ["a","b","c"],
 ["a","b","c"]]
*/
```

## Array

An Array data structure, or simply an Array, is a data structure consisting of a collection of elements (values or variables), each identified by at least one array index or key. The simplest type of data structure is a linear array, also called one-dimensional array. - From Wikipedia

Arrays are among the oldest and most important data structures and are used by every program. They are also used to implement many other data structures.

### Complexity

* **Access:** O(1)	
* **Search:** O(n)
* **Insertion:** O(1)
* **Deletion:** O(n)

```javascript
function MyArray() {
  this.array = [];
}

MyArray.prototype.add = function(data) {
  this.array.push(data);
};

MyArray.prototype.remove = function(data) {
  this.array = this.array.filter(function(current) {
	  return current !== data;
	});
};

MyArray.prototype.search = function(data) {
  let foundIndex = this.array.indexOf(data);
	if(~foundIndex) {
	  return foundIndex;
  }
	return null;
};

MyArray.prototype.getAtIndex = function(index) {
  return this.array[index];
};

MyArray.prototype.length = function() {
  return this.array.length;
};

MyArray.prototype.print = function() {
  console.log(this.array.join(' '));
};

var array = new MyArray();
array.add(1);
array.add(2);
array.add(3);
array.add(4);
array.print(); //-> 1 2 3 4
console.log('search 3 gives index 2:', array.search(3)); //-> search 3 gives index 2: 2
console.log('getAtIndex 2 gives 3:', array.getAtIndex(2)); //-> getAtIndex 2 gives 3: 3
console.log('length is 4:', array.length()); //-> length is 4: 4
array.remove(3);
array.print(); //-> 1 2 4
array.add(5);
array.add(5);
array.print(); //-> 1 2 4 5 5
array.remove(5);
array.print(); //-> 1 2 4
```

## Hash Table

A Hash Table (Hash Map) is a data structure used to implement an associative array, a structure that can map keys to values. A Hash Table uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found. - From Wikipedia

Hash Tables are considered the more efficient data structure for lookup and for this reason, they are widely used.

### Complexity

* **Access:** -	
* **Search:** O(1)
* **Insertion:** O(1)
* **Deletion:** O(1)

Because my calculateHash function is overly simple (mod of the key length) I need to be sure that I am able to save more than one value for every hash. As a consequence I am storing another object for every hash in my Hash Table.

A better example would have had a calculateHash function that returns only one possible hash for every key. I could have done that with a simple JavaScript Object (the hash being the same as the key) but the specificity of the Hash Table data structure is to have this special calculateHash function.

```javascript
function HashTable(size) {
  this.values = {};
  this.numberOfValues = 0;
  this.size = size;
}

HashTable.prototype.add = function(key, value) {
  let hash = this.calculateHash(key);
  if(!this.values.hasOwnProperty(hash)) {
    this.values[hash] = {};
  }
  if(!this.values[hash].hasOwnProperty(key)) {
    this.numberOfValues++;
  }
  this.values[hash][key] = value;
};

HashTable.prototype.remove = function(key) {
  let hash = this.calculateHash(key);
  if(this.values.hasOwnProperty(hash) && this.values[hash].hasOwnProperty(key)) {
    delete this.values[hash][key];
    this.numberOfValues--;
  }
};

HashTable.prototype.calculateHash = function(key) {
  return key.toString().length % this.size;
};

HashTable.prototype.search = function(key) {
  let hash = this.calculateHash(key);
  if(this.values.hasOwnProperty(hash) && this.values[hash].hasOwnProperty(key)) {
    return this.values[hash][key];
  } else {
    return null;
  }
};

HashTable.prototype.length = function() {
  return this.numberOfValues;
};

HashTable.prototype.print = function() {
  let string = '';
  for(var value in this.values) {
    for(var key in this.values[value]) {
      string += this.values[value][key] + ' ';
    }
  }
  console.log(string.trim());
};

var hashTable = new HashTable(3);
hashTable.add('first', 1);
hashTable.add('second', 2);
hashTable.add('third', 3);
hashTable.add('fourth', 4);
hashTable.add('fifth', 5);
hashTable.print(); //-> 2 4 1 3 5
console.log(hashTable.length()); //-> 5
console.log(hashTable.search('second')); //-> 2
hashTable.remove('fourth');
hashTable.remove('first');
hashTable.print(); //-> 2 3 5
console.log(hashTable.length()); //-> 3
```

## Set

A Set is an abstract data type that can store certain values, without any particular order, and no repeated values. It is a computer implementation of the mathematical concept of a finite Set. - From Wikipedia

The Set data structure is usually used to test whether elements belong to set of values. Rather then only containing elements, Sets are more used to perform operations on multiple values at once with methods such as union, intersect, etc…

* **Access:** -	
* **Search:** O(n)
* **Insertion:** O(n)
* **Deletion:** O(n)

```javascript
function Set() {
  this.values = [];
  this.numberOfValues = 0;
}

Set.prototype.add = function(value) {
  if(!~this.values.indexOf(value)) {
    this.values.push(value);
    this.numberOfValues++;
  }
};

Set.prototype.remove = function(value) {
  let index = this.values.indexOf(value);
  if(~index) {
    this.values.splice(index, 1);
    this.numberOfValues--;
  }
};

Set.prototype.contains = function(value) {
  return this.values.indexOf(value) !== -1;
};

Set.prototype.union = function(set) {
  let newSet = new Set();
  set.values.forEach(function(value) {
    newSet.add(value);
  });
  this.values.forEach(function(value) {
    newSet.add(value);
  });
  return newSet;
};

Set.prototype.intersect = function(set) {
  let newSet = new Set();
  this.values.forEach(function(value) {
    if(set.contains(value)) {
      newSet.add(value);
    }
  });
  return newSet;
};

Set.prototype.difference = function(set) {
  let newSet = new Set();
  this.values.forEach(function(value) {
    if(!set.contains(value)) {
      newSet.add(value);
    }
  });
  return newSet;
};

Set.prototype.isSubset = function(set) {
  return set.values.every(function(value) {
    return this.contains(value);
  }, this);
};

Set.prototype.length = function() {
  return this.numberOfValues;
};

Set.prototype.print = function() {
  console.log(this.values.join(' '));
};

var set = new Set();
set.add(1);
set.add(2);
set.add(3);
set.add(4);
set.print(); //-> 1 2 3 4
set.remove(3);
set.print(); //-> 1 2 4
console.log(set.contains(4)); //-> true
console.log(set.contains(3)); //-> false
console.log('---');
var set1 = new Set();
set1.add(1);
set1.add(2);
var set2 = new Set();
set2.add(2);
set2.add(3);
var set3 = set2.union(set1);
set3.print(); // => 1 2 3
var set4 = set2.intersect(set1);
set4.print(); // => 2
var set5 = set.difference(set3); //-> 1 2 4 diff 1 2 3
set5.print(); // => 4
var set6 = set3.difference(set); //-> 1 2 3 diff 1 2 4
set6.print(); // => 3
console.log(set.isSubset(set1)); //-> true
console.log(set.isSubset(set2)); //-> false
console.log(set1.length()); //-> 2
console.log(set3.length()); //-> 3
```

## Singly Linked List

A Singly Linked List is a linear collection of data elements, called nodes pointing to the next node by means of pointer. It is a data structure consisting of a group of nodes which together represent a sequence. Under the simplest form, each node is composed of data and a reference (in other words, a link) to the next node in the sequence. - From Wikipedia

Linked Lists are among the simplest and most common data structures because it allows for efficient insertion or removal of elements from any position in the sequence.

### Complexity

* **Access:** -	O(n)
* **Search:** O(n)
* **Insertion:** O(1)
* **Deletion:** O(1)

```javascript
function Node(data) {
  this.data = data;
  this.next = null;
}

function SinglyLinkedList() {
  this.head = null;
  this.tail = null;
  this.numberOfValues = 0;
}

SinglyLinkedList.prototype.add = function(data) {
  let node = new Node(data);
  if(!this.head) {
    this.head = node;
    this.tail = node;
  } else {
    this.tail.next = node;
    this.tail = node;
  }
  this.numberOfValues++;
};

SinglyLinkedList.prototype.remove = function(data) {
  let previous = this.head;
  let current = this.head;
  while(current) {
    if(current.data === data) {
      if(current === this.head) {
        this.head = this.head.next;
      }
      if(current === this.tail) {
        this.tail = previous;
      }
      previous.next = current.next;
      this.numberOfValues--;
    } else {
      previous = current;
    }
    current = current.next;
  }
};

SinglyLinkedList.prototype.insertAfter = function(data, toNodeData) {
  let current = this.head;
  while(current) {
    if(current.data === toNodeData) {
      var node = new Node(data);
      if(current === this.tail) {
        this.tail.next = node;
        this.tail = node;
      } else {
        node.next = current.next;
        current.next = node;
      }
      this.numberOfValues++;
    }
    current = current.next;
  }
};

SinglyLinkedList.prototype.traverse = function(fn) {
  let current = this.head;
  while(current) {
    if(fn) {
      fn(current);
    }
    current = current.next;
  }
};

SinglyLinkedList.prototype.length = function() {
  return this.numberOfValues;
};
SinglyLinkedList.prototype.print = function() {
  let string = '';
  let current = this.head;
  while(current) {
    string += current.data + ' ';
    current = current.next;
  }
  console.log(string.trim());
};

var singlyLinkedList = new SinglyLinkedList();
singlyLinkedList.print(); //-> ''
singlyLinkedList.add(1);
singlyLinkedList.add(2);
singlyLinkedList.add(3);
singlyLinkedList.add(4);
singlyLinkedList.print(); //-> 1 2 3 4
console.log(singlyLinkedList.length()); //-> 4
singlyLinkedList.remove(3); //-> remove value
singlyLinkedList.print(); //-> 1 2 4
singlyLinkedList.remove(9); //-> remove non existing value
singlyLinkedList.print(); //->> 1 2 4
singlyLinkedList.remove(1); //-> remove head
singlyLinkedList.print(); //-> 2 4
singlyLinkedList.remove(4); //-> remove tail
singlyLinkedList.print(); //-> 2
console.log(singlyLinkedList.length()); //-> 1
singlyLinkedList.add(6);
singlyLinkedList.print(); //-> 2 6
singlyLinkedList.insertAfter(3, 2);
singlyLinkedList.print(); //-> 2 3 6
singlyLinkedList.insertAfter(4, 3);
singlyLinkedList.print(); //-> 2 3 4 6
singlyLinkedList.insertAfter(5, 9); //-> insertAfter a non existing node
singlyLinkedList.print(); //-> 2 3 4 6
singlyLinkedList.insertAfter(5, 4);
singlyLinkedList.insertAfter(7, 6); //-> insertAfter the tail
singlyLinkedList.print(); //-> 2 3 4 5 6 7
singlyLinkedList.add(8); //-> add node with normal method
singlyLinkedList.print(); //-> 2 3 4 5 6 7 8
console.log(singlyLinkedList.length()); //-> 7
singlyLinkedList.traverse(function(node) { node.data = node.data + 10; });
singlyLinkedList.print(); //-> 12 13 14 15 16 17 18
singlyLinkedList.traverse(function(node) { console.log(node.data); }); //-> 12 13 14 15 16 17 18
console.log(singlyLinkedList.length()); //-> 7
```

## Doubly Linked List

A Doubly Linked List is a linked data structure that consists of a set of sequentially linked records called nodes. Each node contains two fields, called links, that are references to the previous and to the next node in the sequence of nodes. - From Wikipedia

Having two node links allow traversal in either direction but adding or removing a node in a doubly linked list requires changing more links than the same operations on a Singly Linked List.

### Complexity

* **Access:** O(n)
* **Search:** O(n)
* **Insertion:** O(1)
* **Deletion:** O(1)

```javascript
function Node(data) {
  this.data = data;
  this.previous = null;
  this.next = null;
}

function DoublyLinkedList() {
  this.head = null;
  this.tail = null;
  this.numberOfValues = 0;
}

DoublyLinkedList.prototype.add = function (data) {
  let node = new Node(data);
  if(!this.head) {
    this.head = node;
    this.tail = node;
  } else {
    node.previous = this.tail;
    this.tail.next = node;
    this.tail = node;
  }
  this.numberOfValues++;
};

DoublyLinkedList.prototype.remove = function(data) {
  let current = this.head;
  while(current) {
    if(current.data === data) {
      if(current === this.head && current === this.tail) {
        this.head = null;
        this.tail = null;
      } else if(current === this.head) {
        this.head = this.head.next;
        this.head.previous = null;
      } else if(current === this.tail) {
        this.tail = this.tail.previous;
        this.tail.next = null;
      } else {
        current.previous.next = current.next;
        current.next.previous = current.previous;
      }
      this.numberOfValues--;
    }
    current = current.next;
  }
};

DoublyLinkedList.prototype.insertAfter = function(data, toNodeData) {
  let current = this.head;
  while(current) {
    if(current.data === toNodeData) {
      var node = new Node(data);
      if(current === this.tail) {
        this.add(data);
      } else {
        current.next.previous = node;
        node.previous = current;
        node.next = current.next;
        current.next = node;
        this.numberOfValues++;
      }
    }
    current = current.next;
  }
};

DoublyLinkedList.prototype.traverse = function(fn) {
  let current = this.head;
  while(current) {
    if(fn) {
      fn(current);
    }
    current = current.next;
  }
};

DoublyLinkedList.prototype.traverseReverse = function(fn) {
  let current = this.tail;
  while(current) {
    if(fn) {
      fn(current);
    }
    current = current.previous;
  }
};

DoublyLinkedList.prototype.length = function() {
  return this.numberOfValues;
};

DoublyLinkedList.prototype.print = function() {
  let string = '';
  let current = this.head;
  while(current) {
    string += current.data + ' ';
    current = current.next;
  }
  console.log(string.trim());
};

var doublyLinkedList = new DoublyLinkedList();
doublyLinkedList.print(); //-> ''
doublyLinkedList.add(1);
doublyLinkedList.add(2);
doublyLinkedList.add(3);
doublyLinkedList.add(4);
doublyLinkedList.print(); //-> 1 2 3 4
console.log(doublyLinkedList.length()); //-> 4
doublyLinkedList.remove(3); //-> remove value
doublyLinkedList.print(); //-> 1 2 4
doublyLinkedList.remove(9); //-> remove non existing value
doublyLinkedList.print(); //-> 1 2 4
doublyLinkedList.remove(1); //-> remove head
doublyLinkedList.print(); //-> 2 4
doublyLinkedList.remove(4); //-> remove tail
doublyLinkedList.print(); //-> 2
console.log(doublyLinkedList.length()); //-> 1
doublyLinkedList.remove(2); //-> remove tail, the list should be empty
doublyLinkedList.print(); //-> ''
console.log(doublyLinkedList.length()); //-> 0
doublyLinkedList.add(2);
doublyLinkedList.add(6);
doublyLinkedList.print(); //-> 2 6
doublyLinkedList.insertAfter(3, 2);
doublyLinkedList.print(); //-> 2 3 6
doublyLinkedList.traverseReverse(function(node) { console.log(node.data); });
doublyLinkedList.insertAfter(4, 3);
doublyLinkedList.print(); //-> 2 3 4 6
doublyLinkedList.insertAfter(5, 9); //-> insertAfter a non existing node
doublyLinkedList.print(); //-> 2 3 4 6
doublyLinkedList.insertAfter(5, 4);
doublyLinkedList.insertAfter(7, 6); //-> insertAfter the tail
doublyLinkedList.print(); //-> 2 3 4 5 6 7
doublyLinkedList.add(8); //-> add node with normal method
doublyLinkedList.print(); //-> 2 3 4 5 6 7 8
console.log(doublyLinkedList.length()); //-> 7
doublyLinkedList.traverse(function(node) { node.data = node.data + 10; });
doublyLinkedList.print(); //-> 12 13 14 15 16 17 18
doublyLinkedList.traverse(function(node) { console.log(node.data); }); //-> 12 13 14 15 16 17 18
console.log(doublyLinkedList.length()); //-> 7
doublyLinkedList.traverseReverse(function(node) { console.log(node.data); }); //-> 18 17 16 15 14 13 12
doublyLinkedList.print(); //-> 12 13 14 15 16 17 18
console.log(doublyLinkedList.length()); //-> 7
```

## Stack

A Stack is an abstract data type that serves as a collection of elements, with two principal operations: push, which adds an element to the collection, and pop, which removes the most recently added element that was not yet removed. The order in which elements come off a Stack gives rise to its alternative name, LIFO (for last in, first out). - From Wikipedia

A Stack often has a third method peek which allows to check the last pushed element without popping it.

### Complexity

* **Access:** O(n)
* **Search:** O(n)
* **Insertion:** O(1)
* **Deletion:** O(1)

```javascript
function Stack() {
  this.stack = [];
}

Stack.prototype.push = function(value) {
  this.stack.push(value);
};

Stack.prototype.pop = function() {
  return this.stack.pop();
};

Stack.prototype.peek = function() {
  return this.stack[this.stack.length - 1];
};

Stack.prototype.length = function() {
  return this.stack.length;
};

Stack.prototype.print = function() {
  console.log(this.stack.join(' '));
};

var stack = new Stack();
stack.push(1);
stack.push(2);
stack.push(3);
stack.print(); //-> 1 2 3
console.log(stack.length()); //-> 3
console.log(stack.peek()); //-> 3
console.log(stack.pop()); //-> 3
stack.print(); //-> 1 2
console.log(stack.pop());  //-> 2
console.log(stack.length()); //-> 1
console.log(stack.pop()); //-> 1
stack.print(); //-> ''
console.log(stack.peek()); //-> undefined
console.log(stack.pop()); //-> undefined
```

## Queue

A Queue is a particular kind of abstract data type or collection in which the entities in the collection are kept in order and the principal operations are the addition of entities to the rear terminal position, known as enqueue, and removal of entities from the front terminal position, known as dequeue. This makes the Queue a First-In-First-Out (FIFO) data structure. In a FIFO data structure, the first element added to the Queue will be the first one to be removed. - From Wikipedia

As for the Stack data structure, a peek operation is often added to the Queue data structure. It returns the value of the front element without dequeuing it.

### Complexity

* **Access:** O(n)
* **Search:** O(n)
* **Insertion:** O(1)
* **Deletion:** O(n)

```javascript
function Queue() {
  this.queue = [];
}

Queue.prototype.enqueue = function(value) {
  this.queue.push(value);
};

Queue.prototype.dequeue = function() {
  return this.queue.shift();
};

Queue.prototype.peek = function() {
  return this.queue[0];
};

Queue.prototype.length = function() {
  return this.queue.length;
};

Queue.prototype.print = function() {
  console.log(this.queue.join(' '));
};

var queue = new Queue();
queue.enqueue(1);
queue.enqueue(2);
queue.enqueue(3);
queue.print(); //-> 1 2 3
console.log(queue.length()); //-> 3
console.log(queue.peek()); //-> 3
console.log(queue.dequeue()); //-> 1
queue.print(); //-> 2 3
console.log(queue.dequeue());  //-> 2
console.log(queue.length()); //-> 1
console.log(queue.dequeue()); //-> 3
queue.print(); //-> ''
console.log(queue.peek()); //-> undefined
console.log(queue.dequeue()); //-> undefined
```

## Tree

A Tree is a widely used data structure that simulates a hierarchical tree structure, with a root value and subtrees of children with a parent node. A tree data structure can be defined recursively as a collection of nodes (starting at a root node), where each node is a data structure consisting of a value, together with a list of references to nodes (the “children”), with the constraints that no reference is duplicated, and none points to the root node. - From Wikipedia

### Complexity

* **Access:** O(n)
* **Search:** O(n)
* **Insertion:** O(n)
* **Deletion:** O(n)

```javascript
function Node(data) {
  this.data = data;
  this.children = [];
}

function Tree() {
  this.root = null;
}

Tree.prototype.add = function(data, toNodeData) {
  let node = new Node(data);
  let parent = toNodeData ? this.findBFS(toNodeData) : null;
  if(parent) {
    parent.children.push(node);
  } else {
    if(!this.root) {
      this.root = node;
    } else {
      return 'Root node is already assigned';
    }
  }
};

Tree.prototype.remove = function(data) {
  if(this.root.data === data) {
    this.root = null;
  }

  let queue = [this.root];
  while(queue.length) {
    let node = queue.shift();
    for(var i = 0; i < node.children.length; i++) {
      if(node.children[i].data === data) {
        node.children.splice(i, 1);
      } else {
        queue.push(node.children[i]);
      }
    }
  }
};

Tree.prototype.contains = function(data) {
  return this.findBFS(data) ? true : false;
};

Tree.prototype.findBFS = function(data) {
  var queue = [this.root];
  while(queue.length) {
    var node = queue.shift();
    if(node.data === data) {
      return node;
    }
    for(var i = 0; i < node.children.length; i++) {
      queue.push(node.children[i]);
    }
  }
  return null;
};

Tree.prototype._preOrder = function(node, fn) {
  if(node) {
    if(fn) {
      fn(node);
    }
    for(var i = 0; i < node.children.length; i++) {
      this._preOrder(node.children[i], fn);
    }
  }
};

Tree.prototype._postOrder = function(node, fn) {
  if(node) {
    for(var i = 0; i < node.children.length; i++) {
      this._postOrder(node.children[i], fn);
    }
    if(fn) {
      fn(node);
    }
  }
};

Tree.prototype.traverseDFS = function(fn, method) {
  let current = this.root;
  if(method) {
    this['_' + method](current, fn);
  } else {
    this._preOrder(current, fn);
  }
};

Tree.prototype.traverseBFS = function(fn) {
  let queue = [this.root];
  while(queue.length) {
    let node = queue.shift();
    if(fn) {
      fn(node);
    }
    for(var i = 0; i < node.children.length; i++) {
      queue.push(node.children[i]);
    }
  }
};

Tree.prototype.print = function() {
  if(!this.root) {
    return console.log('No root node found');
  }
	
  let newline = new Node('|');
  let queue = [this.root, newline];
  let string = '';
  while(queue.length) {
    let node = queue.shift();
    string += node.data.toString() + ' ';
    if(node === newline && queue.length) {
      queue.push(newline);
    }
    for(var i = 0; i < node.children.length; i++) {
      queue.push(node.children[i]);
    }
  }
  console.log(string.slice(0, -2).trim());
};

Tree.prototype.printByLevel = function() {
  if(!this.root) {
    return console.log('No root node found');
  }
	
  let newline = new Node('\n');
  let queue = [this.root, newline];
  let string = '';
  while(queue.length) {
    let node = queue.shift();
    string += node.data.toString() + (node.data !== '\n' ? ' ' : '');
    if(node === newline && queue.length) {
      queue.push(newline);
    }
    for(var i = 0; i < node.children.length; i++) {
      queue.push(node.children[i]);
    }
  }
  console.log(string.trim());
};

var tree = new Tree();
tree.add('ceo');
tree.add('cto', 'ceo');
tree.add('dev1', 'cto');
tree.add('dev2', 'cto');
tree.add('dev3', 'cto');
tree.add('cfo', 'ceo');
tree.add('accountant', 'cfo');
tree.add('cmo', 'ceo');
tree.print(); //-> ceo | cto cfo cmo | dev1 dev2 dev3 accountant
tree.printByLevel();  //-> ceo \n cto cfo cmo \n dev1 dev2 dev3 accountant
console.log(tree.contains('dev1')); //-> true
console.log(tree.contains('dev4')); //-> false
console.log('--- BFS');
tree.traverseBFS(function(node) { console.log(node.data); }); //-> ceo cto cfo cmo dev1 dev2 dev3 accountant
console.log('--- DFS preOrder');
tree.traverseDFS(function(node) { console.log(node.data); }, 'preOrder'); //-> ceo cto dev1 dev2 dev3 cfo accountant cmo
console.log('--- DFS postOrder');
tree.traverseDFS(function(node) { console.log(node.data); }, 'postOrder'); //-> dev1 dev2 dev3 cto accountant cfo cmo ceo
tree.remove('cmo');
tree.print(); //-> ceo | cto cfo | dev1 dev2 dev3 accountant
tree.remove('cfo');
tree.print(); //-> ceo | cto | dev1 dev2 dev3
```

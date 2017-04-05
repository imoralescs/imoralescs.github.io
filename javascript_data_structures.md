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

* **O(log n):** These are the holy grail of search/sort algorithms, they are usually the most efficient approach when dealing with large collections. Instead of looking through the components one by one, they split the data in chunks and discard a large amount on every iteration, usually the half.

* **O(n 2):** Quadratic time complexity is best illustrated with nested for loops. Here, the array provided will be looped through twice. Once for the first loop, but for each index, the array will be looped over again by the second loop. Besides being destructively redundant, the function will take twice as much time for just one additional input.

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

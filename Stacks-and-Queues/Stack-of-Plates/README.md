Imagine a stack of plates. If the stack gets too high, it might topple.
Therefor in real life, we would likely start a new stack when the previous stack exceeds some thresold.

Implement a data structure SetofStacks that mimics this. SetofStacks should be composed of several stacks
and should create a new stack once the previous one exceeds capacity.

SetofStacks.push() and SetofStacks.pop() should behave identically to a single stack.
(i.e. pop should return the same values as it would if there were just a single stack)
Also implement a function popAt(int index) which perform a pop operation on a specific sub-stack.
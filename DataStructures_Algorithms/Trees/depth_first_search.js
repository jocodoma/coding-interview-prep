class Node {
  constructor(value){
    this.left = null;
    this.right = null;
    this.value = value;
  }
}

class BinarySearchTree {
  constructor(){
    this.root = null;
  }
  insert(value){
    const newNode = new Node(value);
    if (this.root === null) {
      this.root = newNode;
    } else {
      let currentNode = this.root;
      while(true){
        if(value < currentNode.value){
          //Left
          if(!currentNode.left){
            currentNode.left = newNode;
            return this;
          }
          currentNode = currentNode.left;
        } else {
          //Right
          if(!currentNode.right){
            currentNode.right = newNode;
            return this;
          }
          currentNode = currentNode.right;
        }
      }
    }
  }
  BreadthFirstSearch(){
    let currentNode = this.root;
    let list = [];
    let queue = [];
    queue.push(currentNode);

    while(queue.length > 0){
      currentNode = queue.shift();
      list.push(currentNode.value);
      if(currentNode.left) {
        queue.push(currentNode.left);
      }
      if(currentNode.right) {
        queue.push(currentNode.right);
      }
    }
    return list;
  }
  BreadthFirstSearch(){
    let currentNode = this.root;
    let list = [];
    let queue = [];
    queue.push(currentNode);

    while(queue.length > 0){
      currentNode = queue.shift();
      list.push(currentNode.value);
      if(currentNode.left) {
        queue.push(currentNode.left);
      }
      if(currentNode.right) {
        queue.push(currentNode.right);
      }
    }
    return list;
  }
  BreadthFirstSearchR(){
    let queue = [];
    queue.push(this.root);
    return traverseBFS(queue, []);
  }
  DFS_PreOrder(){
    return traverseDfsPre(this.root, []);
  }
  DFS_InOrder(){
    return traverseDfsIn(this.root, []);
  }
  DFS_PostOrder(){
    return traverseDfsPost(this.root, []);
  }
}

function traverseBFS(queue, list){
  if(!queue.length){
    return list;
  }
  const currentNode = queue.shift();
  list.push(currentNode.value);
  if(currentNode.left){
    queue.push(currentNode.left);
  }
  if(currentNode.right){
    queue.push(currentNode.right);
  }
  return traverseBFS(queue, list);
}

function traverseDfsPre(node, list){
  list.push(node.value);
  if(node.left){
    traverseDfsPre(node.left, list);
  }
  if(node.right){
    traverseDfsPre(node.right, list);
  }
  return list;
}

function traverseDfsIn(node, list){
  if(node.left){
    traverseDfsIn(node.left, list);
  }
  list.push(node.value);
  if(node.right){
    traverseDfsIn(node.right, list);
  }
  return list;
}

function traverseDfsPost(node, list){
  if(node.left){
    traverseDfsPost(node.left, list);
  }
  if(node.right){
    traverseDfsPost(node.right, list);
  }
  list.push(node.value);
  return list;
}


const tree = new BinarySearchTree();
tree.insert(9)
tree.insert(4)
tree.insert(6)
tree.insert(20)
tree.insert(170)
tree.insert(15)
tree.insert(1)
// tree.remove(170);
// JSON.stringify(traverse(tree.root))

console.log('BFS', tree.BreadthFirstSearch());
console.log('BFS', tree.BreadthFirstSearchR())
console.log('DFS_Pre ', tree.DFS_PreOrder());
console.log('DFS_In  ', tree.DFS_InOrder());
console.log('DFS_Post', tree.DFS_PostOrder());

//     9
//  4     20
//1  6  15  170

function traverse(node) {
  const tree = { value: node.value };
  tree.left = node.left === null ? null : traverse(node.left);
  tree.right = node.right === null ? null : traverse(node.right);
  return tree;
}

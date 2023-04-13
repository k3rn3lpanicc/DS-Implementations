class Node:
    def __init__(self , key , parent=None):
        self.parent = parent
        self.key = key
        self.right = None
        self.left = None
    def set_right(self, node):
        if type(node) == Node:
            self.right = node
        else:
            raise TypeError("node must be Node")
    def set_left(self , node):
        if type(node) == Node:
            self.left = node
        else:
            raise TypeError("node must be Node")
    def get_right(self):
        return self.right
    def get_left(self):
        return self.left
    def set_parent(self , parent):
        if type(parent) is Node:
            self.parent = parent
        else:
            raise TypeError("parent must be Node")
    def get_parent(self):
        return self.parent

class BinarySearchTree:
    def __init__(self) -> None:
        self.root = Node()
        
        self.size = 0
    def search(self, key) -> Node:    
        if self.root.key == None:
            return self.root.parent
        if self.root.key == key:
            return self.root
        else:
            if key < self.root.key:
                return self.search(self.root.get_left())
            else:
                return self.search(self.root.get_right())
    def insert(self, key):
        node = self.search(key)
        if key >= node.key:
            node.set_right(Node(key,node))
        else:
            node.set_left(Node(key,node))
        self.size += 1
    def delete(self, key):
        node = self.search(key)
        if node.get_left() == None and node.get_right() == None:
            if node.get_parent().get_left() == node:
                node.get_parent().set_left(None)
            else:
                node.get_parent().set_right(None)
        

    def print(self):
        print(self.root.key)



use std::rc::Rc;
use std::cell::RefCell;
use std::collections::{HashMap, HashSet, VecDeque};

type Node = Option<Rc<RefCell<TreeNode>>>;

impl Solution {
    pub fn distance_k(
        root: Node,
        target: Node,
        k: i32,
    ) -> Vec<i32> {
        let mut parent: HashMap<*const RefCell<TreeNode>, Rc<RefCell<TreeNode>>> =
            HashMap::new();

        let mut vis: HashSet<*const RefCell<TreeNode>> = HashSet::new();

        fn dfs(
            node: &Node,
            parent: &mut HashMap<*const RefCell<TreeNode>, Rc<RefCell<TreeNode>>>,
        ) {
            if let Some(curr) = node {
                let curr_borrow = curr.borrow();

                if let Some(left) = &curr_borrow.left {
                    parent.insert(Rc::as_ptr(left), Rc::clone(curr));
                    dfs(&Some(Rc::clone(left)), parent);
                }

                if let Some(right) = &curr_borrow.right {
                    parent.insert(Rc::as_ptr(right), Rc::clone(curr));
                    dfs(&Some(Rc::clone(right)), parent);
                }
            }
        }

        dfs(&root, &mut parent);

        let Some(target) = target else {
            return vec![];
        };

        let mut q: VecDeque<(Rc<RefCell<TreeNode>>, i32)> = VecDeque::new();

        q.push_back((Rc::clone(&target), 0));
        vis.insert(Rc::as_ptr(&target));

        let mut ans = Vec::new();

        while let Some((node, dist)) = q.pop_front() {
            if dist == k {
                ans.push(node.borrow().val);
                continue;
            }

            let node_ptr = Rc::as_ptr(&node);

            let (left, right) = {
                let borrowed = node.borrow();
                (
                    borrowed.left.clone(),
                    borrowed.right.clone(),
                )
            };

            if let Some(left) = left {
                let ptr = Rc::as_ptr(&left);
                if vis.insert(ptr) {
                    q.push_back((left, dist + 1));
                }
            }

            if let Some(right) = right {
                let ptr = Rc::as_ptr(&right);
                if vis.insert(ptr) {
                    q.push_back((right, dist + 1));
                }
            }

            if let Some(p) = parent.get(&node_ptr) {
                let ptr = Rc::as_ptr(p);
                if vis.insert(ptr) {
                    q.push_back((Rc::clone(p), dist + 1));
                }
            }
        }

        ans
    }
}
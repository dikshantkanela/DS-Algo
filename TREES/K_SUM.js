class Node{
    constructor(val){
        this.data = parseInt(val);
        this.right = null;
        this.left = null;
    }
}



function createTree(){
    
     let val = prompt("Enter the value of Node : ");
     if(val == -1){
        return null;
     }

     let root = new Node(val);

     root.left = createTree();
     root.right = createTree();
     return root;



}


function kSum(root,k,sum,ans,temp){
    if(root == null){
        return;
    }

    temp.push(root.data);
    sum+=root.data;

    if(root.left == null && root.right == null){
        if(sum == k){
            ans.push([...temp]);
        }
    }

    kSum(root.left,k,sum,ans,temp);
    kSum(root.right,k,sum,ans,temp);

    temp.pop()

}

let root = createTree();
cout<<root;
let ans = [];
let temp = [];
let sum = 0;
let k = 9;

kSum(root,k,sum,ans,temp);

for(let i=0;i<ans.length;i++){
    for(let j=0;j<ans[i].length;j++){
        cout<<ans[i][j];
    }
}


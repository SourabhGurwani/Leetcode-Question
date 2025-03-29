/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    let count=[]
    let j=0
    for(let i=0;i<nums.length;i++){
        if(nums[i]==val){
            count[j]=i
            j++
            
        }
    }
    // console.log(count)
    let m=0
    for(let i=0;i<count.length;i++){
        nums.splice(count[i]-m,1)
        m++
    }
    return nums.length;
    // console.log(nums)
};
// let nums=[3,2,2,3];
// let val=3;
// const result=removeElement(nums,val)
// console.log(result)
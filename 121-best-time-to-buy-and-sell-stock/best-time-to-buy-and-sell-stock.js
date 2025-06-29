/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let minprices=prices[0];
    let maxpro=0;
    for(let i=1;i<prices.length;i++){
        if(minprices>prices[i]){
            minprices=prices[i]
        }
        else{
            let profit=prices[i]-minprices;
            if (profit > maxpro) {
                maxpro = profit;
            }
        }
    }
    return maxpro;
    
};
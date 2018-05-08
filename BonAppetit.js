process.stdin.resume();
process.stdin.setEncoding("ascii");
var input = "";
process.stdin.on("data", function (chunk) {
    input += chunk;
});
process.stdin.on("end", function () {
    // now we can read/parse input

    var list = input.split('\n');
    var l1 = list[0].split(' ');
    var l2 = list[1].split(' ');
    var l3 = list[2];
    
    var len = Number(l1[0]);
    var notPay = Number(l1[1]);
    var totalShare = 0;
    
    for(var i = 0; i < len; i++){
        if(i == notPay){
            continue;
        }
        
        totalShare += Number(l2[i]);
    }
    

    if(totalShare / 2 == Number(l3))
        console.log("Bon Appetit");
    else
        console.log(Number(l3) - totalShare/2);
});



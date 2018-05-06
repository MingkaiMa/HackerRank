'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(str => str.trim());

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the migratoryBirds function below.
function migratoryBirds(n, ar) {

    var dic = {};
    
    for(var i = 0; i < ar.length; i++)
    {
        if(dic[ar[i]] == undefined)
            dic[ar[i]] = 1;
        else
            dic[ar[i]] += 1;
    }
    

    var mostCommon = -Infinity;
    
    for(var x in dic)
    {
        if(dic[x] > mostCommon)
            mostCommon = dic[x];
    }
    

    var res = Infinity;
    
    for(var x in dic) {
        if(dic[x] == mostCommon) {
            if(x < res)
                res = x;
        }
    }

    return res;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const arCount = parseInt(readLine(), 10);

    const ar = readLine().split(' ').map(arTemp => parseInt(arTemp, 10));

    let result = migratoryBirds(arCount, ar);

    ws.write(result + "\n");

    ws.end();
}



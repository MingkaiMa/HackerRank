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

/*
 * Complete the birthdayCakeCandles function below.
 */
function birthdayCakeCandles(n, ar) {
    /*
     * Write your code here.
     */
    
    var len = ar.length;
    var max = -Infinity;
    
    for(var i = 0; i < len; i++)
    {
        if(ar[i] > max)
            max = ar[i];
    }
    
    var res = 0;
    for(var i = 0; i < len; i++)
    {
        if(ar[i] == max)
            res += 1;
    }

    return res;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const n = parseInt(readLine(), 10);

    const ar = readLine().split(' ').map(arTemp => parseInt(arTemp, 10));

    let result = birthdayCakeCandles(n, ar);

    ws.write(result + "\n");

    ws.end();
}



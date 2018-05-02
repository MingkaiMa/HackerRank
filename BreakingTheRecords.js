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
 * Complete the breakingRecords function below.
 */
function breakingRecords(score) {
    /*
     * Write your code here.
     */

    var res = [];
    
    var maxE = score[0];
    var maxRes = 0;
    
    var minE = score[0];
    var minRes = 0;
    
    for(var i = 1; i < score.length; i++)
    {
        if(score[i] > maxE)
        {
            maxE = score[i];
            maxRes += 1;
        }
        
        if(score[i] < minE)
        {
            minE = score[i];
            minRes += 1;
        }
    }
    
    res.push(maxRes);
    res.push(minRes);
    
    return res;
    
    
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const n = parseInt(readLine(), 10);

    const score = readLine().split(' ').map(scoreTemp => parseInt(scoreTemp, 10));

    let result = breakingRecords(score);

    ws.write(result.join(" ") + "\n");

    ws.end();
}



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
 * Complete the getTotalX function below.
 */

function GCD(x, y)
{
    return y == 0 ? x : GCD(y, x % y);
}

function LCM(x, y)
{
    return (x * y) / GCD(x, y);
}

function getTotalX(a, b) {
    /*
     * Write your code here.
     */

    
    var res = 0;
    
    
    var begin_a = 0;
    var begin_b = 0;
    
    if(a.length == 1)
    {
        begin_a = a[0];
    }
    
    if(b.length == 1)
        begin_b = b[0];
    
    if(a.length == 2)
    {
        begin_a = LCM(a[0], a[1]);
    }
    
    if(b.length == 2)
        begin_b = GCD(b[0], b[1]);
    
    
    if(a.length > 2)
    {
        var tmp = LCM(a[0], a[1]);

        
        var i = 2;
        while(i < a.length)
        {
            tmp = LCM(tmp, a[i]);
            i++;
        }
        begin_a = tmp;
    }
    
    if(b.length > 2)
    {
        var tmp = GCD(b[0], b[1]);
        
        var i = 2;
        while(i < b.length)
        {
            tmp = GCD(tmp, b[i]);
            i++;
        }
        begin_b = tmp;
    }
    
    
    for(var i = begin_a; i <= begin_b; i++)
    {
        if(i % begin_a == 0 && begin_b % i == 0)
            res += 1;
    }
    
    return res;
    
    

}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const nm = readLine().split(' ');

    const n = parseInt(nm[0], 10);

    const m = parseInt(nm[1], 10);

    const a = readLine().split(' ').map(aTemp => parseInt(aTemp, 10));

    const b = readLine().split(' ').map(bTemp => parseInt(bTemp, 10));

    let total = getTotalX(a, b);

    ws.write(total + "\n");

    ws.end();
}




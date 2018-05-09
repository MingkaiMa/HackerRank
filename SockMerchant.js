process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();    
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

/////////////// ignore above this line ////////////////////

function sockMerchant(n, ar) {
    // Complete this function
    var dic = {};
    
    for(var i = 0; i < ar.length; i++) {
        if(dic[ar[i]] == undefined)
            dic[ar[i]] = 1;
        else
            dic[ar[i]] += 1;
    }
    
    var res = 0;
    
    for(var x in dic) {
        res += Math.floor(dic[x] / 2);
    }
    
    return res;
}

function main() {
    var n = parseInt(readLine());
    ar = readLine().split(' ');
    ar = ar.map(Number);
    var result = sockMerchant(n, ar);
    process.stdout.write("" + result + "\n");

}

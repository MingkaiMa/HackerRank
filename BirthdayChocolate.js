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

function solve(n, s, d, m){
    // Complete this function
    if(s.length < m){
        return 0;
    }
    
    if(s.length == m){
        var tmpS = 0;
        for(var i = 0; i < s.length; i++){
            tmpS += s[i];
        }
        
        if(tmpS == d)
            return 1;
        return 0;
    }
    
    var res = 0;
    
    var iniSum = 0;
    for(var i = 0; i < m; i++){
        iniSum += s[i];
    }

    for(var i = m; i < s.length; i++){
        if(iniSum == d){
            res += 1;
        }
        
        iniSum = iniSum - s[i - m];
        iniSum = iniSum + s[i];
    }
    
    if(iniSum == d)
        res += 1;
    
    return res;
    
}

function main() {
    var n = parseInt(readLine());
    s = readLine().split(' ');
    s = s.map(Number);
    var d_temp = readLine().split(' ');
    var d = parseInt(d_temp[0]);
    var m = parseInt(d_temp[1]);
    var result = solve(n, s, d, m);
    process.stdout.write(""+result+"\n");

}



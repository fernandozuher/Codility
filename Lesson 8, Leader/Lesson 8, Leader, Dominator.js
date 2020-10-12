// Function mode adapted from: http://rosettacode.org/wiki/Averages/Mode#JavaScript

function mode(ary) {
    let [counter, mode, max] = [{}, A[0], 0]
    for (let i in ary) {
        if (!(ary[i] in counter))
            counter[ary[i]] = 0
        counter[ary[i]]++

        if (counter[ary[i]] > max) {
            max = counter[ary[i]]
            mode = ary[i]
        }
    }
    return mode
}

function solution(A) {
    const mode = mode(A)
    return mode && A.filter(x => x === mode).length > (A.length / 2) ? A.indexOf(mode) : -1
}
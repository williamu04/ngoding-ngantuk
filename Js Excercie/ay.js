function ubah(str){
    let a = str.split(" "); 
    let b = []; 
    for (let i = 0; i < a.length; i++) { 
        let c = a[i].slice(0, 1) + "ay"; 
        let d = a[i].slice(1, a[i].length) + c; 
        b.push(d); 
    } 
    return b.join(" "); 
}

console.log(ubah("aku adalah anak gembala"));
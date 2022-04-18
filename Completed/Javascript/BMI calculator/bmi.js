

function result(){
    // First person variables
    let firstPersonM = document.getElementById("firstPersonM").value;
    let firstPersonH = document.getElementById("firstPersonH").value;
    console.log(firstPersonH);
    // First person calculation
    let firstPersonBMI = Number(firstPersonM) / Number(firstPersonH) ** 2;

    let secondPersonM = document.getElementById("secondPersonM").value;
    let secondPersonH = document.getElementById("secondPersonH").value;
    // Second person calculation
    let secondPersonBMI = secondPersonM / secondPersonH ** 2;

    firstPersonBMI = firstPersonBMI.toFixed(2);
    secondPersonBMI = secondPersonBMI.toFixed(2);

    document.getElementById("firstPersonBMI").innerHTML = "First person's BMI is " + String(firstPersonBMI);
    document.getElementById("secondPersonBMI").innerHTML = "Second person's BMI is " + String(secondPersonBMI);

    if (firstPersonBMI > secondPersonBMI){
        document.getElementById("greaterBMI").innerHTML = "First person's BMI is greater than the second person's bmi. First person's BMI is:  " + String(firstPersonBMI);
    }else {
        document.getElementById("greaterBMI").innerHTML = "Second person's BMI is greater than the first person's bmi. Second person's BMI is:  " + String(secondPersonBMI);
    }
}
const provinces = ["Alberta","BC", "Saskatchewan","Manitoba", "Ontario"];

const federal = [
    [50197, 0.15],
    [50195, 0.205],
    [55233, 0.26],
    [66083, 0.29],
    [0.33]
]

const federalMax = 0.33;

const Alberta = [
    [131220, 0.1],
    [26344, 0.12],
    [52488, 0.13],
    [104976, 0.14]
]

const albertaMax = 0.15;



function taxCalculator(income, province, maxProvince){

    let currentBracket = 0;
    let currentIncome = income;
    let owedTax = 0;

    while(true) {

        if(currentBracket == province.length){
            owedTax += currentIncome * maxProvince;
            break;
        }
        
        if(currentIncome <= province[currentBracket][0]){
            owedTax += currentIncome * province[currentBracket][1];
            break;
        }

        owedTax += province[currentBracket][1] * province[currentBracket][0];
        currentIncome -= province[currentBracket][0];
        currentBracket ++;

    }

    return owedTax;

}

function provinceSelection(){

    const select = document.getElementById("provinceDropDown").value;
    // console.log(select);

    // for(i = 0; i < select.options.length; i++){
    //     if(select.options[i].value == provinces[i]){
    //         selectedProvince = provinces[i];
    //     }
    // }

    let provinceBracket = "";

    switch(select){

        case "Alberta":
            provinceBracket = Alberta;
            break;
        case "BC":
            provinceBracket = BC;
            break;
        case "Saskatchewan":
            provinceBracket = Saskatchewan;
            break;
        case "Manitoba":
            provinceBracket = Manitoba;
            break;
        case "Ontario":
            provinceBracket = Ontario;
            break;
        default:
            provinceBracket = Alberta;

    }

    return provinceBracket;

}

function maxProvinceSelection(selectedProvince){

    let maxProvince = "";

    switch(selectedProvince){

        case "Alberta":
            maxProvince = albertaMax;
            break;
        case "BC":
            maxProvince = BC;
            break;
        case "Saskatchewan":
            maxProvince = Saskatchewan;
            break;
        case "Manitoba":
            maxProvince = Manitoba;
            break;
        case "Ontario":
            maxProvince = Ontario;
            break;
        default:
            maxProvince = albertaMax;

    }

    // console.log(maxProvince);
    return maxProvince;

}


function displayResult(){

    let income = document.getElementById("incomeField").value;
    let selectedProvince = provinceSelection();
    let maxProvince = maxProvinceSelection(selectedProvince);
    let federalTax = taxCalculator(income, federal, federalMax);
    let provincialTax = taxCalculator(income, selectedProvince,maxProvince);

    provincialTax = Number(provincialTax.toFixed(2));
    federalTax = Number(federalTax.toFixed(2));
    let totalTaxResult = federalTax + provincialTax;
    console.log(totalTaxResult);
    totalTaxResult = totalTaxResult.toFixed(2);
    const calculatedSalary = (Number(income) - totalTaxResult).toFixed(2);

    document.getElementById("federalTaxResult").innerHTML = "$" + federalTax;
    document.getElementById("provincialTaxResult").innerHTML = "$" + provincialTax;
    document.getElementById("incomeReminder").innerHTML = "$" + income;
    document.getElementById("totalTaxResult").innerHTML = "$" + totalTaxResult;
    document.getElementById("afterTaxSalary").innerHTML = "$" + calculatedSalary;

}
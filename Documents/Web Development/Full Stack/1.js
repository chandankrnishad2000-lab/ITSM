// employee ={
//     name: "John Doe",
//     age: 30,
//     ismarried: true,
//     skills:{
//         frontend: ["HTML", "CSS", "JavaScript"],
//         backend: ["Node.js", "Express", "MongoDB"]      
//     }
// }

// // extract name and frontend skills from above 
// const { name, skills: { frontend } } = employee;
// console.log(name); 
// console.log(frontend); 


// // print count of backend skills
// const backendSkillsCount = employee.skills.backend.length;
// console.log(backendSkillsCount);

// student task : create an arrow function to print student details
const printStudentDetails = (student) => {
    const { name, age, ismarried, skills } = student;
    console.log(`Name: ${name}`);
    console.log(`Age: ${age}`);
    console.log(`Married: ${ismarried}`);
    console.log(`Skills: ${skills.join(", ")}`);
};

// Example usage:
const student = {
    name: "Jane Smith",
    age: 22,
    ismarried: false,
    skills: ["Python", "Django", "React"]
};

printStudentDetails(student);   

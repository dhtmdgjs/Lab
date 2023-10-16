use std::collections::BTreeMap;
use std::io;

struct Node{
	name : String,
	middle_test_score: i32,
	final_test_score: i32,
}

fn main(){
	let mut student_count = String::new();
	println!("How many students? ");
	
	io::stdin().read_line(&mut student_count)
		.expect("Failed to read line");

	let student_count : usize = student_count.trim().parse()
		.expect("Invalid input");
		
	let mut nametable = Vec::<String>::with_capacity(student_count);
	let mut nodetable = BTreeMap::<String, Node>::new();
	
	for _ in 0..student_count {
	println!("Please enter student information: ");
	
	let mut input = String::new();
	io::stdin().read_line(&mut input)
		.expect("Failed to read line");
		
	let parts: Vec<&str> = input.split_whitespace().collect();
	
	if parts.len() >= 3{
		let name = parts[0].to_string();
		let middle_test_score: i32 = parts[1].parse()
			.expect("Invalid score");
		let final_test_score: i32 = parts[2].parse()
			.expect("Invalid score");
			
	if !nodetable.contains_key(&name) {
		nametable.push(name.clone());
		nodetable.insert(
			name.clone(),
			Node {
				name: name.clone(),
				middle_test_score,
				final_test_score,
			},
		);
		
	println!("\"{}\" has been added to the tree.", name);
	} else {
		println!("\"{}\" already exists in the tree.", name);
	}
	}
}

for (_, node) in &nodetable {
	println!(
		"student_name = {:<10}, middleTest_score = {}, finalTest_score = {}", node.name, node.middle_test_score, node.final_test_score);
		}
	}


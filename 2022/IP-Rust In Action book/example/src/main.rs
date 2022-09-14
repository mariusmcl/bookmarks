fn greet_world() {
    println!("Hello, world!");
    let southern_germany = "Grüß Gott!";
    let japan = "ハロー・ワールド";
    let regions = [southern_germany, japan];
    for region in regions.iter() {
            println!("{}", &region);
    }
}

/* fn main() {
    greet_world();
} */

fn main() {
    let penguin_data = "\
    common name,length (cm)
    Little penguin,33
    Yellow-eyed penguin,65
    Fiordland penguin,60
    Invalid,data
    ";
  
    let records = penguin_data.lines();
    let multi_vec: Vec<_> = ["123", "123"].to_vec();
    println!("multi_vec: {:?}", multi_vec);
    for (i, record) in records.enumerate() {
      if i == 0 || record.trim().len() == 0 {
        continue;
      }
  
      let fields: Vec<_> = record
        .split(',')
        .map(|field| field.trim())
        .collect();
      if cfg!(debug_assertions) {
        eprintln!("debug: {:?} -> {:?}",
               record, fields);
      }
  
      let name = fields[0];
      if let Ok(length) = fields[1].parse::<f32>() {
          println!("{}, {}cm", name, length);
      }
    }
  }
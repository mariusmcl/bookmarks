from tokenizers import Tokenizer
from tokenizers.models import BPE
from tokenizers.pre_tokenizers import Whitespace
from tokenizers.trainers import BpeTrainer


tokenizer = Tokenizer(BPE(unk_token="[UNK]"))

trainer = BpeTrainer(special_tokens=["[UNK]", "[CLS]", "[SEP]", "[PAD]", "[MASK]"])


tokenizer.pre_tokenizer = Whitespace()

files = ["translations.txt"]
tokenizer.train(files, trainer)

tokenizer.save("tokenizer-wiki.json")

# tokenizer = Tokenizer.from_file("data/tokenizer-wiki.json")

output = tokenizer.encode("Hello, y'all! How are you 😁 ?")
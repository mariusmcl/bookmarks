import torch
import torch.nn as nn
    
def create_position_embedding_mtrx(max_seq_len, hidden_size):
    """
    Going to just double loop it (boring...)

    Args:
        max_seq_len (_type_): _description_
        hidden_size (_type_): _description_
    """
    pt = lambda input: torch.tensor(input).float()
    output = torch.zeros((hidden_size, max_seq_len))
    timestamps = torch.linspace(0, max_seq_len, max_seq_len + 1).float()[:-1]
    
    for i in range((hidden_size // 2)):
        output[2*i, :] = torch.sin(timestamps / (max_seq_len ** (2 * pt(i) / hidden_size)))
        output[2*i + 1, :] = torch.cos(timestamps / (max_seq_len ** (2 * pt(i) / hidden_size)))

    if (hidden_size % 2 != 0):
        output[-1, :] = torch.sin(timestamps / max_seq_len)
    return output


class Attention(nn.Module):
    def __init__(self, input_size, output_size, attention_size):
        super().__init__()
        query_head = nn.Linear(input_size, attention_size)
        key_head = nn.Linear(input_size, attention_size)
        value_head = nn.Linear(input_size, output_size)
    
    def forward(self, input):
        q = self.query_head(input)
        k = self.key_head(input)

        

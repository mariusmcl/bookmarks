import imp
import torch
import torch.nn

""" def create_position_embedding_mtrx(max_seq_len, hidden_size):
    output = torch.zeros((max_seq_len, hidden_size))
    
    # x[0]: position in sequence, x[1]: iterator over hidden dim
    sinus = lambda x: torch.sin(x[0] / (max_seq_len ** (2 * x[1] / hidden_size)))
    cosinus = lambda x: torch.cos(x[0] / (max_seq_len ** (2 * x[1] / hidden_size)))
    
    timesteps = torch.linspace(0, max_seq_len, steps=max_seq_len)
    hidden_dimension = torch.linspace(0, hidden_size, steps=hidden_size)
    
    sinusoidal = list(map(sinus,  list(zip(timesteps, hidden_dimension[::2]))))
    cosine = list(map(cosinus,  list(zip(timesteps, hidden_dimension[1::2]))))
    
    output[::2, :] = 
    return """
    
    
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
    def __init__(self, ):
        super().__init__()
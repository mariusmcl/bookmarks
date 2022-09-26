import imp
import torch
import torch.nn

def add_position_embeddings(input_batch):
    """_summary_

    Args:
        input_batch (torch.tensor(N, D, L)): 
    """
    #def 
    output = torch.zeros_like(input_batch)
    output[:, ::2,]
    return
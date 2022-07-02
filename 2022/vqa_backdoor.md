# Dual-key backdoori in VQA models

https://arxiv.org/pdf/2112.07668.pdf

Seems that they rely on having trained the video network THEMSELVES, so they cant alter already-existing models. More a 'trojan' attack than a 'hack': You need to have given the visual model backbone to them themselves. Could anyway be good research... But it could be easily fixed by doing some gradient-steps of fine-tuning in order to change the model and remove the backdoor.

Interesting anyways. but not worthy of much more focus from me 


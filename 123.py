import os,re
from pytube import YouTube
from moviepy.editor import *


os.system('cls')
tes = ["360p","720p","720p","480p","360p","240p","144p"]
tes = ["360","720","720","480","360","240","144"]
biggest = max(tes)
# print(biggest)

sort = sorted(tes, reverse=True)

vidAndItag = {} 

#     # print(res)
# count = Counter(sort)
# # print(count)
# for key,index in count.items():
#     if (index):
#         print(key)
#         ...

itag = []

link = input('masukan link: ')

yt = YouTube(link)
res = yt.streams.filter(file_extension='mp4')
audio = yt.streams.filter(only_audio=True).first()

for result in res:
    result = str(result)
    resVid = result.find('res="')
    vidItag =  result.find('itag=')

    if (resVid != -1 and vidItag):
        endResVid = result.find('"', resVid + 5)
        endVidItag = result.find('"', vidItag + 8)
        
        resResult = result[resVid + 5:endResVid]
        itagResult = result[vidItag + 6:endVidItag]
        vidAndItag[resResult] = itagResult
        
vidAndItagi = {}
sort = sorted(vidAndItag.items(), reverse=True)
video = []



for index in sort:
    vidAndItagi[index[0]] = index[1]
    itag.append(index[1])
    ...
    

for index, sorts in enumerate(sort):
    video.append(sorts[0])
    print(f"{index + 1 }.{sorts[0]}")
    ...

# print(vidAndItagi)
# print(list(vidAndItagi.values())[-1+1])

videoTanpaP = list(map(lambda res: re.sub('p', '' ,res), video))
# print(videoTanpaP)

vDpandItag = {}

for index,videos in enumerate(zip(videoTanpaP, itag)):
    vDpandItag[videos[0]] = videos[1]
    ...

# print(video)

value = input("masukan input: ")

if value.isnumeric():

    if (int(value) < len(video)):
        value = list(vidAndItagi.values())[-1+int(value)]
        stream = yt.streams.get_by_itag(value).download()
        ...

    elif (value in videoTanpaP):
        value = vDpandItag[f'{value}']
        stream = yt.streams.get_by_itag(value).download()
        ...

    else:
        print('👎')

elif value in video:
    value = vidAndItagi[f'{value}']
    stream = yt.streams.get_by_itag(value).download()
    ...
    
else:
    print('salah')



name = f'{yt.title}.mp4'
nami = f'{yt.title}.mp3'
os.rename(name,'video.mp4')

audio.download()
os.rename(name,'audio.mp3')

viClip = VideoFileClip('video.mp4')
auClip = AudioFileClip('audio.mp3')

final = viClip.set_audio(auClip)
final.write_videofile(name)



























# if (value) < len(video) :
#     print(value)
#     ...



        
# for key,value in vidAndItag.items():
#     print(key,value)


























# video = []
# itagVid = []

# videoAndItag = {}

# for res in a:
#     tes = res.find('res="')
#     tesi = res.find('itag="')
#     if (tes != -1 and tesi):
#         resValue = res.find('"', tes + 5)
#         itagValue = res.find('"', tesi + 8)
#         # print(resValue)
#         resResult = res[tes + 5:resValue]
#         itagResult = res[tesi + 6:itagValue]
#         # print(resResult, itagResult)
#         videoAndItag[resResult] = itagResult
        
# for itag in a:
#     itagi = itag.find('itag="')
#     resItag = itag.find('"', itagi + 8)
#     itagResult = itag[itagi + 6:resItag]
#     # print(itagResult) 
    
# notes = sorted(videoAndItag.items(), reverse=True)

# # print(notes)

# videoAndItag = {}

# for key in notes:
#     videoAndItag[key[0]] = key[1]
#     video.append(key[0])
#     itagVid.append(key[1])
#     # print(key[1])
#     for index in key:
#         ...
        
# # for video, itag in enumerate(zip(video,itagVid)):
# #     # print(video,itag)
# #     # print(video,itag)
# #     # pilihan = input("masukan pilihan: ")
# #     ...
    
# for res in video:
#     print(res) 
    
# # print(len(video))
    
# for vidAndItag in itag:
#     ...
        


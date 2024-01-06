import pygame
import pygame_gui
import sys
from ctypes import CDLL
backend_lib = CDLL('sequencealigner')
pygame.init()

WIDTH, HEIGHT = 1600, 900
SCREEN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption('Sequence Aligner')

manager = pygame_gui.UIManager((1600, 900))

text_input = pygame_gui.elements.UITextEntryLine(relative_rect=pygame.Rect((350, 275), (900, 50)), manager=manager,
                                               object_id='#input_seq')

text_input2 = pygame_gui.elements.UITextEntryLine(relative_rect=pygame.Rect((350, 500), (900, 50)), manager=manager,
                                               object_id='#ref_seq')

clock = pygame.time.Clock()
count = 0
def show_user_name(inputseq, refseq):
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        SCREEN.fill("white")
        nt = backend_lib.find_snps(inputseq, refseq)
        if count < len(nt):
            count += 1
        
        #new_text = pygame.font.SysFont("bahnschrift", 100).render(f"Hello, {inputseq} {refseq}", True, "black")
        #muts = backend_lib.frontend_snps(inputseq, refseq) 
        new_text = pygame.font.SysFont("bahnschrift", 100).render(f"Hello, {nt}", True, "black")
        new_text_rect = new_text.get_rect(center=(WIDTH/2, HEIGHT/2))
        SCREEN.blit(new_text, new_text_rect)
        #new_text = pygame.font.SysFont("bahnschrift", 100).render(f"Hello, {backend_lib.main(inputseq, refseq)}", True, "black")
        #new_text_rect = new_text.get_rect(center=(WIDTH/2, HEIGHT/2))
        #SCREEN.blit(new_text, new_text_rect)

        clock.tick(60)
        #backend_lib.some_function()
        pygame.display.update()

def get_user_name():
    switch = 0
    while True:
        UI_REFRESH_RATE = clock.tick(60)/1000
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if (event.type == pygame_gui.UI_TEXT_ENTRY_FINISHED and event.ui_object_id == '#input_seq'):
                switch = 1
                inputseq = event.text
            if (event.type == pygame_gui.UI_TEXT_ENTRY_FINISHED and event.ui_object_id == '#ref_seq' and switch == 1):
                show_user_name(inputseq, event.text)
            manager.process_events(event)
        
        manager.update(UI_REFRESH_RATE)

        SCREEN.fill("white")

        manager.draw_ui(SCREEN)

        pygame.display.update()
    

get_user_name()
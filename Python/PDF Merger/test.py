import PyPDF2

def merge_pdfs(pdf_list, output_filename):
    merger = PyPDF2.PdfMerger()
    
    for pdf in pdf_list:
        merger.append(pdf)
    
    merger.write(output_filename)
    merger.close()
    print(f"Merged PDF saved as '{output_filename}'")

if __name__ == "__main__":
    pdf_files = ["file1.pdf", "file2.pdf", "file3.pdf"]  # Replace with a list of your PDF file paths
    output_file = "Tennis_Kumar_documents.pdf"
    merge_pdfs(pdf_files, output_file)

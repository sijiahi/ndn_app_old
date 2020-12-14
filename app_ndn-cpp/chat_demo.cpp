#include "chat_demo.h"
#include "ui_chat_demo.h"
#include "chat_setter.h"
Chat_demo::Chat_demo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chat_demo),
    m_setter(new chat_setter(this))
{
    //connect(this,SIGNAL(newMsg(QString)),
    //        &m_backend, SLOT(sendChatMessage(QString, time_t)));
    m_name = "";
    m_prefix = "";
    m_chatroom =  "";
    connect(m_setter, SIGNAL(chatInfoUpdate(const QString&,const QString&,const QString&)),
             this, SLOT(onChatStart(const QString&,const QString&,const QString&)));
    ui->setupUi(this);
    //chatDebug();
}


Chat_demo::~Chat_demo()
{
    delete ui;
}

void
Chat_demo::on_Send_clicked()
{
    QString text = ui->Input_field->text();
    if (text.toStdString().empty())
      return;
    ui->Input_field->clear();
    if (text.toStdString() == "leave" || text == "exit")
      // We will send the leave message below.
      return;
    m_chat->sendMessage(text.toStdString());
    //m_chat.sendMessage(text.toStdString());
   // m_chat->sendMessage(text.toStdString());
    m_face->processEvents();
    appendChatMessage(m_name,text);
    //emit newMsg(text, timestamp);
}
// Show Setter and get information needed
bool Chat_demo::Initiate(){
    try{
    m_setter->show();
    }
    catch (std::exception& e) {
      std::cerr << "Exception thrown while initializing chat:" << e.what() << std::endl;
      return false;
    }
}
void
Chat_demo::onChatStart(const QString& name,const QString& prefix,const QString& chatroom){

        m_name = name;
        m_prefix = prefix;
        m_chatroom = chatroom;
        const char* host = "localhost";
        std::cout << "Connecting to " << host << ", Chatroom: " << chatroom.toStdString() <<
          ", Username: " << name.toStdString() << std::endl;
      try{
        KeyChain keyChain("pib-memory:", "tpm-memory:");
        keyChain.importSafeBag(SafeBag
          (Name("/testname/KEY/123"),
           Blob(DEFAULT_RSA_PRIVATE_KEY_DER, sizeof(DEFAULT_RSA_PRIVATE_KEY_DER)),
           Blob(DEFAULT_RSA_PUBLIC_KEY_DER, sizeof(DEFAULT_RSA_PUBLIC_KEY_DER))));

        m_face = new Face(host);
        m_face->setCommandSigningInfo(keyChain, keyChain.getDefaultCertificateName());

       /* ptr_lib::shared_ptr<chat_core> chat(new chat_core
            (name.toStdString(), chatroom.toStdString(), Name(prefix.toStdString()), *m_face, keyChain,
            keyChain.getDefaultCertificateName()));
        chat->initialize();
        chat_core* chat1 = chat.get();*/
        //ndn::Face face = m_face;
        m_chat = new Chat
                (this,name.toStdString(), chatroom.toStdString(), Name(prefix.toStdString()), m_face, keyChain,
                keyChain.getDefaultCertificateName());
        m_chat->initialize();
        connect(m_chat, SIGNAL(chatDataReceived(QString,QString)),
                this, SLOT(onChatDataReceived(QString,QString)));

        this->show();
        appendControlMessage(m_name,QString("is entring chatroom"));
        usleep(100000);
            m_face->processEvents();
        m_chat->start();
        }
        catch (std::exception& e) {
            QMessageBox errorBox;
            QString errormsg = "Error occurs when initiazing Chat with message ";
            errormsg=errormsg+QString::fromStdString(e.what());
            errorBox.setWindowTitle("Error");
            errorBox.setText(errormsg);
             cout << "Exception Thrown while Starting Chat Dialog: " << e.what() << endl;
           }




}
void
Chat_demo::onControlMessageReceived(const QString& name,const QString& content){
    appendControlMessage(name, content);
}
void
Chat_demo::onChatDataReceived(const QString& name,const QString& content){
    appendChatMessage(name, content);
}

void Chat_demo::appendChatMessage(const QString& name, const QString& message)
{
      QTextCharFormat nickFormat;
      nickFormat.setForeground(Qt::darkGreen);
      nickFormat.setFontWeight(QFont::Bold);
      nickFormat.setFontUnderline(true);
      nickFormat.setUnderlineColor(Qt::gray);

      // Print who & when
      QTextCursor cursor(ui->textEdit->textCursor());
      cursor.movePosition(QTextCursor::End);
      QTextTableFormat tableFormat;
      tableFormat.setBorder(0);
      QTextTable *table = cursor.insertTable(1, 2, tableFormat);
      QString from = QString("%1 ").arg(name);
      QTextTableCell fromCell = table->cellAt(0, 0);
      fromCell.setFormat(nickFormat);
      fromCell.firstCursorPosition().insertText(from);

      // Print what
      QTextCursor nextCursor(ui->textEdit->textCursor());
      nextCursor.movePosition(QTextCursor::End);
      table = nextCursor.insertTable(1, 1, tableFormat);
      table->cellAt(0, 0).firstCursorPosition().insertText(message);

      // Popup notification
      //showMessage(from, message);

      QScrollBar *bar = ui->textEdit->verticalScrollBar();
      bar->setValue(bar->maximum());
}
void
Chat_demo::appendControlMessage(const QString& name,
                                 const QString& message)
{
  QTextCharFormat nickFormat;
  nickFormat.setForeground(Qt::gray);
  nickFormat.setFontWeight(QFont::Bold);
  nickFormat.setFontUnderline(true);
  nickFormat.setUnderlineColor(Qt::gray);

  QTextCursor cursor(ui->textEdit->textCursor());
  cursor.movePosition(QTextCursor::End);
  QTextTableFormat tableFormat;
  tableFormat.setBorder(0);
  QTextTable *table = cursor.insertTable(1, 2, tableFormat);

  QString controlMsg = QString("%1 %2  ").arg(name).arg(message);
  QTextTableCell fromCell = table->cellAt(0, 0);
  fromCell.setFormat(nickFormat);
  fromCell.firstCursorPosition().insertText(controlMsg);
  //printTimeInCell(table, timestamp);
}

int
Chat_demo::chatDebug()
{
  try {
    // Silence the warning from Interest wire encode.
    Interest::setDefaultCanBePrefix(true);

    cout << "Enter your chat username:" << endl;
    string screenName = stdinReadLine();

    string defaultHubPrefix = "ndn/edu/ucla/remap";
    cout << "Enter your hub prefix [" << defaultHubPrefix << "]" << endl;
    string hubPrefix = stdinReadLine();
    if (hubPrefix == "")
      hubPrefix = defaultHubPrefix;

    string defaultChatRoom = "ndnchat";
    cout << "Enter the chatroom name [" << defaultChatRoom << "]:" << endl;
    string chatRoom = stdinReadLine();
    if (chatRoom == "")
      chatRoom = defaultChatRoom;

    const char* host = "localhost";
    cout << "Connecting to " << host << ", Chatroom: " << chatRoom <<
      ", Username: " << screenName << endl << endl;

    Face face(host);

    // Set up the key chain.
    KeyChain keyChain("pib-memory:", "tpm-memory:");
    keyChain.importSafeBag(SafeBag
      (Name("/testname/KEY/123"),
       Blob(DEFAULT_RSA_PRIVATE_KEY_DER, sizeof(DEFAULT_RSA_PRIVATE_KEY_DER)),
       Blob(DEFAULT_RSA_PUBLIC_KEY_DER, sizeof(DEFAULT_RSA_PUBLIC_KEY_DER))));
    face.setCommandSigningInfo(keyChain, keyChain.getDefaultCertificateName());

    m_chat = new Chat
            (this,screenName, chatRoom, Name(hubPrefix), &face, keyChain,
             keyChain.getDefaultCertificateName());
    m_chat->start();
    /*ptr_lib::shared_ptr<Chat> chat(new Chat
      (screenName, chatRoom, Name(hubPrefix), face, keyChain,
       keyChain.getDefaultCertificateName()));
    chat->initialize();*/

    // The main loop to process Chat while checking stdin to send a message.
    cout << "Enter your chat message. To quit, enter \"leave\" or \"exit\"." << endl;
    while (true) {
      if (isStdinReady()) {
        string input = stdinReadLine();
        if (input == "leave" || input == "exit")
          // We will send the leave message below.
          break;
        m_chat->sendMessage(input);
        ui->Input_field->setText(QString::fromStdString(input));
        this->on_Send_clicked();
      }
        m_chat->sendMessage("test");
      face.processEvents();
      // We need to sleep for a few milliseconds so we don't use 100% of the CPU.
      usleep(10000);
    }

    // The user entered the command to leave.
    m_chat->leave();
    // Wait a little bit to allow other applications to fetch the leave message.
    ndn_MillisecondsSince1970 startTime = Chat::getNowMilliseconds();
    while (true)
    {
      if (Chat::getNowMilliseconds() - startTime >= 1000.0)
        break;

      face.processEvents();
      usleep(10000);
    }
  } catch (std::exception& e) {
    cout << "exception: " << e.what() << endl;
  }
  return 0;
}


